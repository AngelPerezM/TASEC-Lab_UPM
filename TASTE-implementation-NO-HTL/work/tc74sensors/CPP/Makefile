VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-tc74sensors.h \
                  ../../dataview/C/Context-tc74sensors.c \
                  src/tc74sensors.h \
                  src/tc74sensors.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
