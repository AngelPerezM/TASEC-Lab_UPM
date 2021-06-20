VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-gpsreader.h \
                  ../../dataview/C/Context-gpsreader.c \
                  src/gpsreader.h \
                  src/gpsreader.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
