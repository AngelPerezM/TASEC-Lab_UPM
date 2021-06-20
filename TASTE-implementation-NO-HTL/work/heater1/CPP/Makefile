VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-heater1.h \
                  ../../dataview/C/Context-heater1.c \
                  src/heater1.h \
                  src/heater1.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
