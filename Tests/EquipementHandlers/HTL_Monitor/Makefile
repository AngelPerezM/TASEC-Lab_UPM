NAME_BIN := htl_monitor
LDLIBS := -l:EquipementHandlers/equipementHandlers.a \
  		-l:BusHandlers/busHandlers.a -l:Utils/utils.a \
		-lgps -lm -lpigpiod_if2 -lrt -lpigpio

include ../../common_test.mk
