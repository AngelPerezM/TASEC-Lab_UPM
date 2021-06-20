VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-anemometer.h \
                  ../../dataview/C/Context-anemometer.c \
                  src/anemometer.h \
                  src/anemometer.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
