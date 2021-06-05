VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-heater.h \
                  ../../dataview/C/Context-heater.c \
                  src/heater.h \
                  src/heater.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
