VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-anemometer-mock.h \
                  ../../dataview/C/Context-anemometer-mock.c \
                  src/anemometer_mock.h \
                  src/anemometer_mock.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
