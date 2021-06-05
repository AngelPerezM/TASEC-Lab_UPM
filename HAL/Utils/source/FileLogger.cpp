/*******************************************************************************
 * source/FileLogger.cpp
 * Author: Ángel Pérez
 *
 * 15/8/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "FileLogger.h"
#include "Debug.h"

#include <chrono>
#include <iostream>


/* Defines section
 *******************************************************************************/

/* Function definitions
 *******************************************************************************/

namespace utils {

  FileLogger::FileLogger(const FileLogger &fl) : mFileName(fl.mFileName) {
    mOutputFileStream.open(mFileName, std::ofstream::app);
    PRINT_DEBUG("Copy constructor\n");
  }

  FileLogger::FileLogger(std::string fileName) : mFileName(fileName) {
    mOutputFileStream.open(mFileName, std::ofstream::app);
    PRINT_DEBUG("Constructor\n");
  }

  FileLogger& FileLogger::operator=(const FileLogger &fl) {
    mFileName = fl.mFileName;
    mOutputFileStream.open(mFileName, std::ofstream::app);

    PRINT_DEBUG("end");
    return *this;
  }

  FileLogger::~FileLogger() {

    if (mOutputFileStream.is_open()) {
      PRINT_DEBUG("%s was openned\n", mFileName.c_str());
      mOutputFileStream.close();
    }

    mFileName = "";
    PRINT_DEBUG("End\n");

  }

  bool FileLogger::operator==(const FileLogger &fl) const {
    return fl.mFileName == this->mFileName;
  }

  void FileLogger::setFileName(const std::string fileName) {
    mFileName = fileName;
    if (mOutputFileStream.is_open()) {
      mOutputFileStream.close();
    }
    mOutputFileStream.open(mFileName, std::ofstream::app);
  }

  void FileLogger::log(Level level, std::string message, const char* func,
                       const char* file, const int line)
  {	    
    const std::string dateTime = getCurrentDateTime();
    const std::string logMessage =
      getLevelMessage(level) + " in " + func  + " (" + file + ":" + std::to_string(line) + "):\n" +
      message + "\n";
      
    mtx.lock();
    mOutputFileStream << "[" << dateTime << "] " << logMessage << std::endl;
    mtx.unlock();
    
#ifdef DEBUG
    std::cout << logMessage << std::endl;
#endif
  }

  const std::string FileLogger::getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);

    char buf[81];
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
  }

  const std::string FileLogger::getLevelMessage(int level)
  {
    std::string messages [] = {"EMERGENCY", "ALERT", "ERROR", "WARNING", "INFO"};
    return messages[level];
  }
}
