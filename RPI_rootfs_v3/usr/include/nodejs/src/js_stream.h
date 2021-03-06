#ifndef SRC_JS_STREAM_H_
#define SRC_JS_STREAM_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "async_wrap.h"
#include "env.h"
#include "stream_base.h"
#include "v8.h"

namespace node {

class JSStream : public AsyncWrap, public StreamBase {
 public:
  static void Initialize(v8::Local<v8::Object> target,
                         v8::Local<v8::Value> unused,
                         v8::Local<v8::Context> context);

  bool IsAlive() override;
  bool IsClosing() override;
  int ReadStart() override;
  int ReadStop() override;

  int DoShutdown(ShutdownWrap* req_wrap) override;
  int DoWrite(std::unique_ptr<WriteWrap>& w,
              uv_buf_t* bufs,
              size_t count,
              uv_stream_t* send_handle) override;

  SET_NO_MEMORY_INFO()
  SET_MEMORY_INFO_NAME(JSStream)
  SET_SELF_SIZE(JSStream)

 protected:
  JSStream(Environment* env, v8::Local<v8::Object> obj);

  AsyncWrap* GetAsyncWrap() override;

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void ReadBuffer(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void EmitEOF(const v8::FunctionCallbackInfo<v8::Value>& args);

  static void OnAllocImpl(size_t size, uv_buf_t* buf, void* ctx);
  static void OnReadImpl(ssize_t nread,
                         const uv_buf_t* buf,
                         uv_handle_type pending,
                         void* ctx);

  template <class Wrap>
  static void Finish(const v8::FunctionCallbackInfo<v8::Value>& args);
};

}  // namespace node

#endif  // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif  // SRC_JS_STREAM_H_
