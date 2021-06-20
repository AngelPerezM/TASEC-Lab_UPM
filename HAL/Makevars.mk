# Name of commands to be used:
MV		:=mv -f
RM		:=rm -f
SED		:=sed
AR		:=ar
ARFLAGS		:=-crs

# Name of extensions:
EXT_SRC 	:=cpp
EXT_HEAD	:=h
EXT_OBJ		:=o
EXT_DEP		:=d

# Definition of paths:
# Note that this file HAS to be in the root directory of your project (DIR_ROOT)
CWD 		 =$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DIR_ROOT	:=$(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))
DIR_INC		?=$(CWD)/include $(DIR_ROOT)/include
DIR_SRC		?=$(CWD)/source
DIR_OBJ		?=$(CWD)/build
DIR_TEST	?=$(CWD)/test
DIR_LIB		?=$(CWD)/lib
DIR_BIN		?=$(CWD)/binaries
$(info [INFO] DIR_ROOT: $(DIR_ROOT))
$(info [INFO] CWD: $(CWD))

# Files:
SOURCES		:=$(wildcard $(DIR_SRC)/*.$(EXT_SRC))
OBJECTS		:=$(patsubst $(DIR_SRC)/%.$(EXT_SRC),$(DIR_OBJ)/%.$(EXT_OBJ),$(SOURCES))
DEPENDENCIES	:=$(OBJECTS:.$(EXT_OBJ)=.$(EXT_DEP))
$(info [INFO] Sources: $(SOURCES))
$(info [INFO] Objects: $(OBJECTS))
$(info [INFO] Dependencies: $(DEPENDENCIES))

# Compiler variables:
ARCH =$(shell arch)
$(info [INFO] Host architecture: $(ARCH))
ifeq ($(ARCH), x86_64)
    CXX	=arm-linux-gnueabihf-g++ --sysroot=$(DIR_ROOT)/../RPI_roots_v3 
else
    CXX =g++
endif
CXXFLAGS	=-std=c++11
DEPFLAGS	=-MMD # Only user dependencies.

COMON_FLAGS 	:= -Wall -Wextra -Werror -Wformat=2 -Wlogical-op -Wduplicated-cond\
			-Wduplicated-branches $(addprefix -I,$(DIR_INC)) -pipe\
			$(addprefix -L,$(DIR_LIB) $(DIR_ROOT)/lib)

# Default option is debug mode.
BUILD_DEBUG ?= yes
ifeq ($(BUILD_DEBUG), yes)  # -- Debug mode?
  COMON_FLAGS += -g -DDEBUG -O0
  $(info [INFO] All files will be compiled in debug mode.)
else
  COMON_FLAGS += -Os # <--- for size optimization. Default by G++: O0.
  $(info [INFO] All files will be compiled in release mode.)
endif
################################################################################
