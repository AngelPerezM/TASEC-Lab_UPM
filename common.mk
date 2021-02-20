MV		:=mv -f
RM		:=rm -f
SED		:=sed
EXT_SRC 	:=cpp
AR		:=ar
ARFLAGS		:=-crs

# Definition of paths:
DIR_ROOT	?=..
CWD 		 =$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DIR_INC		:=$(CWD)/include $(DIR_ROOT)/include
DIR_SRC		:=$(CWD)/source
DIR_OBJ		:=$(CWD)/build
DIR_TEST	:=$(CWD)/test
DIR_LIB		:=$(CWD)/lib
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
		-Wduplicated-branches $(addprefix -I ,$(DIR_INC))

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

.PRECIOUS: bin
bin: $(DIR_BIN)/$(NAME_BIN)

$(DIR_BIN)/$(NAME_BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

.PHONY: lib
lib: $(DIR_LIB)/$(NAME_LIB)

$(DIR_LIB)/$(NAME_LIB): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

$(OBJECTS): $(DIR_OBJ)/%.o: $(DIR_SRC)/%.$(EXT_SRC) $(DIR_OBJ)/%.d
	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) -c $< -o $@ $(LDLIBS)

.PHONY: test run_test
test: lib $(DIR_TEST)/$(NAME_TEST) run_test

$(DIR_TEST)/$(NAME_TEST): $(DIR_TEST)/$(NAME_TEST).$(EXT_SRC)
	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) $< -o $@ $(LDLIBS)

run_test:
	$(DIR_TEST)/$(NAME_TEST)

.PHONY: clean
clean:
	$(RM) -r $(DIR_OBJ)
	$(RM) -r $(DIR_LIB)

.PHONY: directories
directories:
	mkdir -p $(DIR_OBJ)
	mkdir -p $(DIR_LIB)
	mkdir -p $(DIR_BIN)

.PRECIOUS: $(DEPENDENCIES)
$(DEPENDENCIES): $(DIR_OBJ)/%.d: ;

-include $(DEPENDENCIES)
