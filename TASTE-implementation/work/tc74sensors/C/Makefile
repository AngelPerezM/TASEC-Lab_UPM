VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/tc74sensors.h \
                  src/tc74sensors.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
