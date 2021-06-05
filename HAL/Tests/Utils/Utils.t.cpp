#include <gtest/gtest.h>

#include "CircularBufferTest.h"
#include "FileLogger.t.h"
#include "FileLoggerFactory.t.h"

int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
