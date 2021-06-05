#ifndef FILE_LOGGER_FACTORY_H
#define FILE_LOGGER_FACTORY_H

#include <unordered_map>
#include <stdint.h>

#include "FileLogger.h"

namespace utils {
  class FileLoggerFactory {
    private:
      std::unordered_map <const char*, FileLogger*> fileLoggers;

      FileLoggerFactory();

      FileLoggerFactory(const FileLoggerFactory&) = delete;

      FileLoggerFactory& operator=(const FileLoggerFactory&) = delete;

      ~FileLoggerFactory();

    public:
      
      /**
       * Since c++11 local static are thread safe.
       */
      static FileLoggerFactory &getInstance() {
        static FileLoggerFactory uniqueInstance;
        return uniqueInstance;
      }

      FileLogger * createFileLogger(const char *fileName);

  };
}

#endif // FILE_LOGGER_FACTORY_H
