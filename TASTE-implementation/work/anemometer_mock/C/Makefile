VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/anemometer_mock.h \
                  src/anemometer_mock.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
