#ifndef CIRCULARBUFFERTEST_H
#define CIRCULARBUFFERTEST_H

#include "CircularBuffer.h"
#include <gtest/gtest.h>

using namespace utils;

namespace utils {
  class CircularBufferTest : public ::testing::Test {
    protected:
      CircularBufferTest() {
        ;
      }

      virtual void SetUp() override {
        /* cb1 = std::unique_ptr<CircularBuffer<int>>(new CircularBuffer<int>(5));
           cb2 = std::unique_ptr<CircularBuffer<int>>(new CircularBuffer<int>(5));
           cb3 = std::unique_ptr<CircularBuffer<int>>(new CircularBuffer<int>(5));
           cb4 = std::unique_ptr<CircularBuffer<int>>(new CircularBuffer<int>(5));
           cb5 = std::unique_ptr<CircularBuffer<int>>(new CircularBuffer<int>(5)); */
      };

      virtual void TearDown() override {
        ;
      }

      /* std::unique_ptr<CircularBuffer<int>> cb1;
         std::unique_ptr<CircularBuffer<int>> cb2;
         std::unique_ptr<CircularBuffer<int>> cb3;
         std::unique_ptr<CircularBuffer<int>> cb4;
         std::unique_ptr<CircularBuffer<int>> cb5; */
  };		

  TEST_F(CircularBufferTest, insertAndExtractOneElement) {
    CircularBuffer<int> cb1(5);

    EXPECT_TRUE(cb1.put(1));
    EXPECT_FALSE(cb1.isFull());

    int extracted = -1;
    EXPECT_TRUE(cb1.get(extracted));
    EXPECT_EQ(1, extracted);

    EXPECT_TRUE(cb1.isEmpty());
  }

  TEST_F(CircularBufferTest, insertTwo_ExtractOne) {
    CircularBuffer<int> cb(5);

    EXPECT_TRUE(cb.put(1));
    EXPECT_TRUE(cb.put(2));

    int extracted = -1;
    EXPECT_TRUE(cb.get(extracted));
    EXPECT_EQ(1, extracted);
    EXPECT_TRUE(cb.get(extracted));
    EXPECT_EQ(2, extracted);

    EXPECT_TRUE(cb.isEmpty());
    EXPECT_FALSE(cb.isFull());
  }

  TEST_F(CircularBufferTest, overflowDestructiveBuffer) {
    CircularBuffer<int> cb(5);
    cb.setDestructive(true);

    for(int i = 1; i <= 10; ++i)
      EXPECT_TRUE(cb.put(i));
    EXPECT_TRUE(cb.isFull());
    EXPECT_FALSE(cb.isEmpty());

    for(int i = 6; i <= 10; ++i) {
      int extracted = -1;
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    EXPECT_TRUE(cb.isEmpty());

  }

  TEST_F(CircularBufferTest, overflowNonDestructiveBuffer) {
    CircularBuffer<int> cb(5);
    cb.setDestructive(false);

    for(int i = 1; i <= 5; ++i)
      EXPECT_TRUE(cb.put(i));
    EXPECT_TRUE(cb.isFull());

    for(int i = 6; i <= 10; ++i)
      EXPECT_FALSE(cb.put(i));
    EXPECT_TRUE(cb.isFull());

    for(int i = 1; i <= 5; ++i) {
      int extracted = -1;
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    EXPECT_TRUE(cb.isEmpty());
    EXPECT_FALSE(cb.isFull());

  }

  TEST_F(CircularBufferTest, combinedInsertionsAndDelations) {
    CircularBuffer<int> cb(5);
    cb.setDestructive(false);
    int extracted = -1;

    for(int i = 1; i <= 3; ++i)
      EXPECT_TRUE(cb.put(i));

    for(int i = 1; i <= 3; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    // Now is empty.
    EXPECT_TRUE(cb.isEmpty());

    // if empty cant return anything
    EXPECT_FALSE(cb.get(extracted));

    for(int i = 6; i <= 10; ++i)
      EXPECT_TRUE(cb.put(i));
    // 10 9 8 7 6

    EXPECT_TRUE(cb.isFull());

    for(int i = 6; i <= 8; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    // should have only 9 and 10.
    EXPECT_EQ(2, cb.getSize());

    for(int i = 20; i <= 22; ++i)
      EXPECT_TRUE(cb.put(i));			
    // added 20 and 22, cb should have 22 21 20 10 9
    EXPECT_TRUE(cb.isFull());

    for(int i = 9; i <= 10; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    EXPECT_EQ(3, cb.getSize());

    for(int i = 20; i <= 22; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }			
    EXPECT_TRUE(cb.isEmpty());

    // if empty cant return anything
    EXPECT_FALSE(cb.get(extracted));

  }

  TEST_F(CircularBufferTest, combinedInsertionsAndDelations_Destructive) {
    CircularBuffer<int> cb(5);
    cb.setDestructive(true);
    int extracted = -1;

    for(int i = 1; i <= 10; ++i)
      EXPECT_TRUE(cb.put(i));
    // 10 9 8 7 6
    EXPECT_TRUE(cb.isFull());

    for(int i = 6; i <= 8; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    // 10 9
    EXPECT_EQ(2, cb.getSize());

    for(int i = 50; i <= 70; ++i)
      EXPECT_TRUE(cb.put(i));
    EXPECT_TRUE(cb.isFull());

    // 70 69 68 67 66
    for(int i = 66; i <= 70; ++i) {
      EXPECT_TRUE(cb.get(extracted));
      EXPECT_EQ(i, extracted);
    }
    EXPECT_TRUE(cb.isEmpty());
  }

}

#endif // CIRCULARBUFFERTEST_H
