VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/functioninstance1.h src/functioninstance1.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
