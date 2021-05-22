NAME_BIN := Main.t
LDLIBS := -l:EquipementHandlers/equipementHandlers.a \
  		-l:BusHandlers/busHandlers.a -l:Utils/utils.a \
		-lgps -lm -lpigpiod_if2 -lrt -lgtest -lpthread \
		-lpigpio -latomic

include ../common_test.mk
