#include "Utils/FileLogger.h"

#include "gtest/gtest.h"
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdio.h>

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

      bool fileExist(const char *name) {
        std::ifstream file;
        file.open(name);
        bool exist = (bool) file;
        file.close();

        return exist;
      }

      int getFileSize(const char *name) {
        std::ifstream file (name, std::ios::binary);
        file.seekg(0, std::ios::end);
        return file.tellg();
      }

  };

  TEST_F(FileLoggerTest, constructor) {
    FileLogger fl ("log.txt");
    fl.~FileLogger();

    ASSERT_TRUE(fileExist("log.txt"));
  }

  TEST_F(FileLoggerTest, ManyMessagesTest) {
    FileLogger fl ("ManyMessagesLog.txt");
    for(int i = 0; i < 100; ++i) {
      fl.LOG((i%2 == 0)?(Info):(Debug), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }
    for(int i = 0; i < 100; ++i) {
      fl.LOG((i%2 == 0)?(Warning):(Error), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_TRUE(fileExist("ManyMessagesLog.txt"));
    ASSERT_EQ(20230, getFileSize("ManyMessagesLog.txt"));
      
    ::remove("ManyMessagesLog.txt");
  }

}
