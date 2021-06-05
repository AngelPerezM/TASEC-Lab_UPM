# Definition of paths:
DIR_ROOT :=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export DIR_ROOT # export to subdirs

bus_handlers	:=$(DIR_ROOT)/BusHandlers
eq_handlers	:=$(DIR_ROOT)/EquipementHandlers
utils		:=$(DIR_ROOT)/Utils

components	:=$(utils) $(bus_handlers) $(eq_handlers)
#main		:=$(DIR_ROOT)/Main

$(info Main Component: $(main))
$(info Components: $(components))
.PHONY: all
all: directories $(components) $(main)

.PHONY: lib
lib: directories $(components)

.PHONY: $(main)
$(main): $(components)
	@echo "###############################################################################"
	@echo "# $@"
	@echo "###############################################################################"
	$(MAKE) --directory=$@ $(TARGET)

.PHONY: $(components)
$(components):
	@echo "###############################################################################"
	@echo "# $@"
	@echo "###############################################################################"
	$(MAKE) --directory=$@ $(TARGET)
	ln -sfnr $(@)/lib $(DIR_ROOT)/lib/$(subst $(DIR_ROOT)/,,$(@))
	ln -sfnr $(@)/include $(DIR_ROOT)/include/$(subst $(DIR_ROOT)/,,$(@))

.PHONY: test
test:	$(components)
	$(MAKE) --directory=$(DIR_ROOT)/Tests
	$(MAKE) --directory=$(DIR_ROOT)/Tests TARGET=check

.PHONY: directories
directories:
	mkdir -p lib
