VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/i2cdevsreader.h src/i2cdevsreader.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
