VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-heater2.h \
                  ../../dataview/C/Context-heater2.c \
                  src/heater2.h \
                  src/heater2.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
