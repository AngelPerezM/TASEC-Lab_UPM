#include "BusHandlers/SPIHandler.h"
#include "gtest/gtest.h"
#include <stdio.h>

class SPIHandlerTest : public testing::Test {
  protected:

    SPIHandlerTest() : testing::Test(), 
      sh1(0, 0, 10000), sh2(1, 0, 10000)
    {
    }

    void SetUp() override {
      ;
    }

    void printHexBuffer(const uint8_t *buf, const uint32_t size) {
      printf("[");
      for (uint32_t i = 0; i < (size-1); ++i) {
        printf("%02X, ", buf[i]);
      }
      printf("%02X]\n", (size > 0)? (buf[size-1]):(0));
    }

    busHandlers::SPIHandler sh1;
    busHandlers::SPIHandler sh2;
};

TEST_F(SPIHandlerTest, TransferFewByte) {
  uint8_t tx[] = {0x14};
  uint8_t rx[] = {0xFF};
  
  printf("BEFORE:\n");
  printf(" - tx: "); printHexBuffer(tx, 1);
  printf(" - rx: "); printHexBuffer(rx, 1);
  sh2.transfer(tx, rx, sizeof(tx), 10);
  printf("AFTER:\n");
  printf(" - tx: "); printHexBuffer(tx, 1);
  printf(" - rx: "); printHexBuffer(rx, 1);

  ASSERT_EQ(tx[0], rx[0]);
}

TEST_F(SPIHandlerTest, transferManyBytes) {
  uint8_t tx[] = {0x20, 0x21, 0x22, 0x23};
  uint8_t rx[] = {0xFF, 0xFF, 0xFF, 0xFF};
  uint32_t nBytes = sizeof(tx);

  printf("BEFORE:\n");
  printf(" - tx: "); printHexBuffer(tx, nBytes);
  printf(" - rx: "); printHexBuffer(rx, nBytes);
  sh2.transfer(tx, rx, nBytes, 10);
  printf("AFTER:\n");
  printf(" - tx: "); printHexBuffer(tx, nBytes);
  printf(" - rx: "); printHexBuffer(rx, nBytes);

  for (uint32_t i = 0; i < nBytes; ++i) {
    ASSERT_EQ(tx[1], rx[1]);
  }
}

TEST_F(SPIHandlerTest, transferALotOfBytes) {
  uint8_t tx[] = {0x20, 0x21, 0x22, 0x23, 0x30, 0x31, 0x32 ,0x33, 0x34};
  uint8_t rx[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint32_t nBytes = sizeof(tx);

  printf("BEFORE:\n");
  printf(" - tx: "); printHexBuffer(tx, nBytes);
  printf(" - rx: "); printHexBuffer(rx, nBytes);
  sh2.transfer(tx, rx, nBytes, 10);
  printf("AFTER:\n");
  printf(" - tx: "); printHexBuffer(tx, nBytes);
  printf(" - rx: "); printHexBuffer(rx, nBytes);

  for (uint32_t i = 0; i < nBytes; ++i) {
    ASSERT_EQ(tx[1], rx[1]);
  }
}
