#include "Utils/FileLoggerFactory.h"
#include "gtest/gtest.h"
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <signal.h>

namespace utils {
  class FileLoggerFactoryTest : public ::testing::Test {
    protected:

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

      FileLoggerFactory &ff = FileLoggerFactory::getInstance();
  };

  TEST_F(FileLoggerFactoryTest, DoesNotReturnNull) {
    const char *fileName = "Logs/UntouchedLog.txt";
    FileLogger *fl = ff.createFileLogger(fileName);

    ASSERT_NE(fl, nullptr);

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_GT(getFileSize(fileName), 0);
  }

  
  TEST_F(FileLoggerFactoryTest, TwoLoggersManyMessagesTest) {
    const char *fileName = "Logs/TwoLoggersManyMessagesTest.txt";
    removeFileContent(fileName);
    FileLogger *fl1 = ff.createFileLogger(fileName);
    FileLogger *fl2 = ff.createFileLogger(fileName);

    ASSERT_EQ(fl1, fl2) << "The two file logger references are not the same.\n";

    for(int i = 0; i < 100; ++i) {
      fl1->LOG((i%2 == 0)?(Info):(Emergency), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(10940, getFileSize(fileName));

    for(int i = 0; i < 100; ++i) {
      fl2->LOG((i%2 == 0)?(Warning):(Error), "Message " + std::to_string(i) + ".");
      usleep(2500);
    }

    ASSERT_PRED1(fileExist, fileName);
    ASSERT_EQ(21830, getFileSize(fileName));
  }

  /*
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
*/
}
