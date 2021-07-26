# Definition of paths:
DIR_ROOT :=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export DIR_ROOT # export to subdirs

bus_handlers	:=$(DIR_ROOT)/BusHandlers
eq_handlers	:=$(DIR_ROOT)/EquipementHandlers
utils		:=$(DIR_ROOT)/Utils

components	:=$(utils) $(bus_handlers) $(eq_handlers)

.PHONY: all
all clean: directories $(components)
	for dir in $(components); do\
		echo "# $$dir";\
		echo "###############################################################################";\
		$(MAKE) --directory=$$dir $(@);\
		ln -sfnr $$dir/lib $(DIR_ROOT)/lib/$(subst $(DIR_ROOT)/,,$(dir));\
		ln -sfnr $$dir/include $(DIR_ROOT)/include/$(subst $(DIR_ROOT)/,,$(dir));\
	done


.PHONY: clean
clean: directories $(components)

.PHONY: test
test:	$(components)
	$(MAKE) --directory=$(DIR_ROOT)/Tests
	$(MAKE) --directory=$(DIR_ROOT)/Tests TARGET=check

.PHONY: directories
directories:
	mkdir -p lib
