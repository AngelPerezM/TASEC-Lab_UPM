VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/pt1000sensors.h \
                  src/pt1000sensors.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
