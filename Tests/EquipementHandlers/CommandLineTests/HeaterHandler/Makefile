NAME_BIN := heater
LDLIBS := -l:EquipementHandlers/equipementHandlers.a \
  		-l:BusHandlers/busHandlers.a -l:Utils/utils.a \
		-lgps -lm -lpigpiod_if2 -lrt

include ../../../common_test.mk
