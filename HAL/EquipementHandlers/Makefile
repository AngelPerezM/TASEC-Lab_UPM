################################################################################
include ../Makevars.mk

# Name of the static library to be created
NAME_LIB=equipementHandlers.a
# Name of the executable
NAME_BIN=
# Name of the test
NAME_TEST=
# Additional libraries to be loaded when compiling.
LDLIBS  = -lgps -lm -lgpiodcxx -lpigpiod_if2 -lrt

# If you want to create a librarie add lib, if you want an executable add bin.
.PHONY: all
all: directories lib # <--- add here.

include ../Makerules.mk
################################################################################
