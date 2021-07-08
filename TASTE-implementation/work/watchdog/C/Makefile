VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-watchdog.h \
                  ../../dataview/C/Context-watchdog.c \
                  src/watchdog.h \
                  src/watchdog.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
