VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  ../../dataview/C/Context-datapool.h \
                  ../../dataview/C/Context-datapool.c \
                  src/datapool.h \
                  src/datapool.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
