#include "Utils/FileLogger.h"
#include "gtest/gtest.h"
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <signal.h>

namespace utils {
  class FileLoggerTest : public ::testing::Test {
    protected:

      FileLoggerTest() {
        ;
      }

      virtual void SetUp() override {

      }

      virtual void TearDown() override {

      }

      static void removeFileContent(const char *name) {
        std::ofstream ofs;
        ofs.open(name, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
      }

      static bool fileExist(const char *name) {
        std::ifstream file;
        file.open(name);
        bool exist = (bool) file;
        file.close();

        return exist;
      }

      static int getFileSize(const char *name) {
        std::ifstream file (name, std::ios::binary);
        file.seekg(0, std::ios::end);
        return file.tellg();
      }

  };

  TEST_F(FileLoggerTest, UntochedLog) {
    const char *fileName = "Logs/UntochedLog.txt";
    FileLogger *fl = new FileLogger(fileName);

    int originalSize = getFileSize(fileName);

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_GT(originalSize, 0);
    
    delete fl;

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(originalSize, getFileSize(fileName)); 
  }

  TEST_F(FileLoggerTest, constructor) {
    removeFileContent("log.txt");
    FileLogger fl ("log.txt");
    fl.~FileLogger();

    ASSERT_PRED1(fileExist, "log.txt");
    ASSERT_EQ(0, getFileSize("log.txt"));
  }

  TEST_F(FileLoggerTest, ManyMessagesTest) {
    const char *fileName = "Logs/ManyMessagesTest.txt";
    removeFileContent(fileName);
    FileLogger fl (fileName);

    ASSERT_EQ(0, getFileSize(fileName));
    
    for(int i = 0; i < 100; ++i) {
      fl.LOG((i%2 == 0)?(Info):(Emergency), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(10240, getFileSize(fileName));

    for(int i = 0; i < 100; ++i) {
      fl.LOG((i%2 == 0)?(Warning):(Error), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(20430, getFileSize(fileName));
  }

  TEST_F(FileLoggerTest, SavedContentsWithoutClose) {
    const char *fileName = "Logs/SavedContentsWithoutClose.txt"; 
    removeFileContent(fileName);
    FileLogger *fl = new FileLogger(fileName);

    ASSERT_EQ(0, getFileSize(fileName));

    for(int i = 0; i < 100; ++i) {
      fl->LOG((i%2 == 0)?(Info):(Emergency), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(10340, getFileSize(fileName));
    
    delete fl;

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(10340, getFileSize(fileName));
    
  }

}
