#ifndef B2S_EXCEPTION_H
#define B2S_EXCEPTION_H

#include <exception>
#include <iostream>
#include <sstream>
#include <string.h> // strerror

namespace utils {

  /**
   * Define base class exception to be inherit by each component exception class.
   * B2S because of the B2Space project.
   */
  class B2SException : public std::exception {
    private:
      std::string m_errorMsg;
      int m_errCode;

    public:

      B2SException(const std::string &errorMsg, const char *func,
                   const char *file = __FILE__, int line = __LINE__)
      {
        std::ostringstream o;
        o << "[" << func << "] " << file << " in line " << line << ":\n"
          << "\t" << errorMsg;
        m_errorMsg = o.str();
      }

      B2SException(const std::string &errorMsg, int errorCode, const char *func,
                   const char *file = __FILE__, int line = __LINE__)
      {
        std::ostringstream o;
        o << "[" << func << "] " << file << " in line " << line << ":\n"
          << "\t" << errorMsg << ".\n"
          << "\t" << strerror(errorCode);
        
        m_errorMsg = o.str();
      }

      virtual ~B2SException() {
        ;
      }

      virtual const char* what() /*const throw ()*/{
        return m_errorMsg.c_str();
      }

      int getErrCode() {
       return m_errCode;
     }

  };
}

#endif // B2S_EXCEPTION_H
