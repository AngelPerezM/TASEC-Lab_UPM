# Definition of paths:
CWD =$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

bus_handlers	:=#$(CWD)/BusHandlers
eq_handlers	:=$(CWD)/EquipementHandlers

tests		:=$(bus_handlers) $(eq_handlers)

.PHONY: all
all: $(tests)

.PHONY: $(tests)
$(tests):
	@echo "###############################################################################"
	@echo "# Test: $@"
	@echo "###############################################################################"
	$(MAKE) --directory=$@ $(TARGET)
