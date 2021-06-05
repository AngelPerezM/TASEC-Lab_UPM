#ifndef FILELOGGER_H
#define FILELOGGER_H

/*******************************************************************************
 * include/FileLogger.h
 * Author: Ángel Pérez
 *
 * 15/8/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <string>
#include <fstream>
#include <string>
#include <mutex>          // std::mutex

/* Defines section
 *******************************************************************************/
#define SOURCE_OF_INFO  __FILE__ "(" + std::to_string(__LINE__) + ")"
#define LOG(level, message) \
  log(level, message, __func__, __FILE__, __LINE__)

namespace utils {

  enum Level {
    Emergency,  /* Nothing can be done. */
    Alert,      /* The problem should be corrected inmediately. */
    Error,      /* Error conditions. */
    Warning,    /* Potential error. */
    Info,       /* Informational message. */
  };

  class FileLogger {

    public:

      // CONSTRUCTORS

      FileLogger(const FileLogger &fl);

      FileLogger(std::string fileName);

      FileLogger& operator=(const FileLogger &fl);
      // DESTRUCTOR

      ~FileLogger();

      // MANIPULATORS

      void log(Level level, std::string message, const char* func,
               const char* file, const int line);

      void setFileName(const std::string fileName);

      bool operator==(const FileLogger &fl) const;

      // ACCESORS

    private:

      std::ofstream mOutputFileStream;
      std::string mFileName;
      std::mutex mtx;           // mutex for critical section

      // MANIPULATORS

      const std::string createLogMessage(Level level, std::string message);

      // ACCESORS

      const std::string getCurrentDateTime();

      const std::string getLevelMessage(int level);
  };

}

#endif
