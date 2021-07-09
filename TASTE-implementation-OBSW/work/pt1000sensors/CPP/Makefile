VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-pt1000sensors.h \
                  ../../dataview/C/Context-pt1000sensors.c \
                  src/pt1000sensors.h \
                  src/pt1000sensors.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
