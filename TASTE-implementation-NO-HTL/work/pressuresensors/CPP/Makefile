VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-pressuresensors.h \
                  ../../dataview/C/Context-pressuresensors.c \
                  src/pressuresensors.h \
                  src/pressuresensors.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
