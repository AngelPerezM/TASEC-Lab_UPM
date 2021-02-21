# Definition of paths:
MY_DIR		:=$(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))
CWD 		 =$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DIR_SRC		:=$(CWD)
DIR_TEST	:=$(CWD)
DIR_LIB		:=$(CWD)

include $(MY_DIR)/../Makevars.mk

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
