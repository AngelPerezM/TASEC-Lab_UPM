#include "FileLoggerFactory.h"
#include "Debug.h"

namespace utils {

  FileLoggerFactory::FileLoggerFactory() {
    PRINT_DEBUG("\n");
  }

  FileLoggerFactory::~FileLoggerFactory() {
    while(!fileLoggers.empty())
    {
      std::unordered_map<const char *, FileLogger*>::iterator it = fileLoggers.begin();
      fileLoggers.erase(it);
    }
    PRINT_DEBUG("end.\n");
  }

  FileLogger * FileLoggerFactory::createFileLogger(const char *fileName) {
    if(0 == fileLoggers.count(fileName)) {
      fileLoggers.insert(std::make_pair(fileName, new FileLogger(fileName)));
      PRINT_DEBUG("Creating new file logger for %s\n", fileName);
    }
    
    PRINT_DEBUG("end.\n");
    return fileLoggers.at(fileName);

  }

}
