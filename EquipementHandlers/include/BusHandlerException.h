#ifndef BUS_HANDLER_EXCEPTION_H
#define BUS_HANDLER_EXCEPTION_H

#include <exception>
#include <iostream>
#include <sstream>

namespace busHandlers {
  class BusHandlerException : public std::exception {
    private:
      std::string m_errorMsg;
    public:

      BusHandlerException(const std::string &errorMsg,
                          const char *func = __FUNCTION__,
                          const char *file = __FILE__,
                          int line = __LINE__)
      {
        std::ostringstream o;
        o << "[" << func << "] " << file << " in line " << line << ":\n"
          << "\t" << errorMsg;
        m_errorMsg = o.str();
      }

      virtual ~BusHandlerException() {}

      virtual const char* what() const throw (){
        return m_errorMsg.c_str();
      }

  };
}

#endif // BUS_HANDLER_EXCEPTION_H
