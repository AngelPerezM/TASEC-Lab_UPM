MV		:=mv -f
RM		:=rm -f
SED		:=sed
EXT_SRC 	:=cpp
AR		:=ar
ARFLAGS		:=-crs

# Definition of paths:
CWD 		 =$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DIR_ROOT	?=../..
DIR_INC		:=$(DIR_ROOT)/include
DIR_SRC		:=$(CWD)
DIR_OBJ		:=$(CWD)/build
DIR_BIN		:=$(CWD)/binaries

# Files:
SOURCES		:=$(wildcard $(DIR_SRC)/*.$(EXT_SRC))
OBJECTS		:=$(patsubst $(DIR_SRC)/%.$(EXT_SRC),$(DIR_OBJ)/%.o,$(SOURCES))
DEPENDENCIES	:=$(OBJECTS:.o=.d)
$(info [INFO] Sourecs: $(SOURCES))
$(info [INFO] Objects: $(OBJECTS))
$(info [INFO] Dependencies: $(DEPENDENCIES))

# Compiler variables:
CXX =g++
CXXFLAGS =-std=c++11
DEPFLAGS =-MMD

COMON_FLAGS := -Wall -Wextra -Werror -Wformat=2 -pipe \
		-Wlogical-op -Wduplicated-cond \
		-Wduplicated-branches $(addprefix -I ,$(DIR_INC)) \
		-L$(DIR_ROOT)/lib

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

.PRECIOUS: all
all: directories bin

.PRECIOUS: bin
bin: $(DIR_BIN)/$(NAME_BIN)

$(DIR_BIN)/$(NAME_BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) $(DIR_OBJ)/$(NAME_BIN).o -o $@ $(LDLIBS)

$(OBJECTS): $(DIR_OBJ)/%.o: $(DIR_SRC)/%.$(EXT_SRC) $(DIR_OBJ)/%.d
	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) -c $< -o $@ $(LDLIBS)
	
.PRECIOUS: directories
directories:
	mkdir -p $(DIR_OBJ)
	mkdir -p $(DIR_BIN)

.PRECIOUS: clean
clean:
	$(RM) -r $(DIR_OBJ)
	$(RM) -r $(DIR_BIN)

.PRECIOUS: check
check: directories bin
	$(DIR_BIN)/$(NAME_BIN)

.PRECIOUS: $(DEPENDENCIES)
$(DEPENDENCIES): $(DIR_OBJ)/%d: ;

-include $(DEPENDENCIES)
