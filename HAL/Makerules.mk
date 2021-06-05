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

#.PHONY: test run_test
#test: lib $(DIR_TEST)/$(NAME_TEST) run_test
#
#$(DIR_TEST)/$(NAME_TEST): $(DIR_TEST)/$(NAME_TEST).$(EXT_SRC)
#	$(CXX) $(CXXFLAGS) $(COMON_FLAGS) $(DEPFLAGS) $< -o $@ $(LDLIBS)

#run_test:
#	$(DIR_TEST)/$(NAME_TEST)

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
################################################################################
