// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SRC_TLS_WRAP_H_
#define SRC_TLS_WRAP_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node.h"
#include "node_crypto.h"  // SSLWrap

#include "async_wrap.h"
#include "env.h"
#include "stream_wrap.h"
#include "v8.h"

#include <openssl/ssl.h>

#include <string>

namespace node {

// Forward-declarations
class WriteWrap;
namespace crypto {
class SecureContext;
class NodeBIO;
}

class TLSWrap : public AsyncWrap,
                public crypto::SSLWrap<TLSWrap>,
                public StreamBase,
                public StreamListener {
 public:
  ~TLSWrap() override;

  static void Initialize(v8::Local<v8::Object> target,
                         v8::Local<v8::Value> unused,
                         v8::Local<v8::Context> context);

  int GetFD() override;
  bool IsAlive() override;
  bool IsClosing() override;

  // JavaScript functions
  int ReadStart() override;
  int ReadStop() override;

  ShutdownWrap* CreateShutdownWrap(
      v8::Local<v8::Object> req_wrap_object) override;
  int DoShutdown(ShutdownWrap* req_wrap) override;
  int DoWrite(std::unique_ptr<WriteWrap>& w,
              uv_buf_t* bufs,
              size_t count,
              uv_stream_t* send_handle) override;
  // Return error_ string or nullptr if it's empty.
  const char* Error() const override;
  // Reset error_ string to empty. Not related to "clear text".
  void ClearError() override;

  void NewSessionDoneCb();

  void MemoryInfo(MemoryTracker* tracker) const override;

  SET_MEMORY_INFO_NAME(TLSWrap)
  SET_SELF_SIZE(TLSWrap)

  std::string diagnostic_name() const override;

 protected:
  inline StreamBase* underlying_stream() {
    return static_cast<StreamBase*>(stream_);
  }

  static const int kClearOutChunkSize = 16384;

  // Maximum number of bytes for hello parser
  static const int kMaxHelloLength = 16384;

  // Usual ServerHello + Certificate size
  static const int kInitialClientBufferLength = 4096;

  // Maximum number of buffers passed to uv_write()
  static const int kSimultaneousBufferCount = 10;

  TLSWrap(Environment* env,
          Kind kind,
          StreamBase* stream,
          crypto::SecureContext* sc);

  static void SSLInfoCallback(const SSL* ssl_, int where, int ret);
  void InitSSL();
  // SSL has a "clear" text (unencrypted) side (to/from the node API) and
  // encrypted ("enc") text side (to/from the underlying socket/stream).
  // On each side data flows "in" or "out" of SSL context.
  //
  // EncIn() doesn't exist. Encrypted data is pushed from underlying stream into
  // enc_in_ via the stream listener's OnStreamAlloc()/OnStreamRead() interface.
  void EncOut();  // Write encrypted data from enc_out_ to underlying stream.
  void ClearIn();  // SSL_write() clear data "in" to SSL.
  void ClearOut();  // SSL_read() clear text "out" from SSL.

  // Call Done() on outstanding WriteWrap request.
  bool InvokeQueued(int status, const char* error_str = nullptr);

  // Drive the SSL state machine by attempting to SSL_read() and SSL_write() to
  // it. Transparent handshakes mean SSL_read() might trigger I/O on the
  // underlying stream even if there is no clear text to read or write.
  inline void Cycle() {
    // Prevent recursion
    if (++cycle_depth_ > 1)
      return;

    for (; cycle_depth_ > 0; cycle_depth_--) {
      ClearIn();
      ClearOut();
      // EncIn() doesn't exist, it happens via stream listener callbacks.
      EncOut();
    }
  }

  AsyncWrap* GetAsyncWrap() override;
  bool IsIPCPipe() override;

  // Resource implementation
  void OnStreamAfterWrite(WriteWrap* w, int status) override;
  uv_buf_t OnStreamAlloc(size_t size) override;
  void OnStreamRead(ssize_t nread, const uv_buf_t& buf) override;

  v8::Local<v8::Value> GetSSLError(int status, int* err, std::string* msg);

  static void OnClientHelloParseEnd(void* arg);
  static void Wrap(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void Receive(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void SetVerifyMode(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void EnableSessionCallbacks(
      const v8::FunctionCallbackInfo<v8::Value>& args);
  static void EnableKeylogCallback(
      const v8::FunctionCallbackInfo<v8::Value>& args);
  static void EnableTrace(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void EnableCertCb(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void DestroySSL(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void GetServername(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void SetServername(const v8::FunctionCallbackInfo<v8::Value>& args);
  static int SelectSNIContextCallback(SSL* s, int* ad, void* arg);

  crypto::SecureContext* sc_;
  // BIO buffers hold encrypted data.
  BIO* enc_in_ = nullptr;   // StreamListener fills this for SSL_read().
  BIO* enc_out_ = nullptr;  // SSL_write()/handshake fills this for EncOut().
  // Waiting for ClearIn() to pass to SSL_write().
  std::vector<char> pending_cleartext_input_;
  size_t write_size_ = 0;
  std::unique_ptr<WriteWrap> current_write_ = nullptr;
  WriteWrap* current_empty_write_ = nullptr;
  bool write_callback_scheduled_ = false;
  bool started_ = false;
  bool established_ = false;
  bool shutdown_ = false;
  std::string error_;
  int cycle_depth_ = 0;

  // If true - delivered EOF to the js-land, either after `close_notify`, or
  // after the `UV_EOF` on socket.
  bool eof_ = false;

 private:
  static void GetWriteQueueSize(
      const v8::FunctionCallbackInfo<v8::Value>& info);
};

}  // namespace node

#endif  // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif  // SRC_TLS_WRAP_H_
