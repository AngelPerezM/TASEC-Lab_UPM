# Definition of paths:
DIR_ROOT :=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export DIR_ROOT # export to subdirs

bus_handlers	:=$(DIR_ROOT)/BusHandlers
eq_handlers	:=$(DIR_ROOT)/EquipementHandlers
utils		:=$(DIR_ROOT)/Utils

components	:=$(utils) $(bus_handlers) $(eq_handlers)

define exec_subdirs
    @echo "# $1";\
    @echo "###############################################################################";\
    ln -sfnr $(1)/lib $(DIR_ROOT)/lib/$(subst $(DIR_ROOT)/,,$(1));\
    ln -sfnr $(1)/include $(DIR_ROOT)/include/$(subst $(DIR_ROOT)/,,$(1));\
    $(MAKE) --directory=$(1) $(2);
endef

.PHONY: all
all clean: directories $(components)
	$(foreach dir, $(components), $(call exec_subdirs,$(dir),$(@)))\

.PHONY: clean
clean: directories $(components)

.PHONY: test
test:	$(components)
	$(MAKE) --directory=$(DIR_ROOT)/Tests
	$(MAKE) --directory=$(DIR_ROOT)/Tests TARGET=check

.PHONY: directories
directories:
	mkdir -p lib
