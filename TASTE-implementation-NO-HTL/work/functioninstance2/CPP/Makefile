VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/functioninstance2.h src/functioninstance2.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
