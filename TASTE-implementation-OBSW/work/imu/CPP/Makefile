VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h src/imu.h src/imu.cc

compile-linux:
	mkdir -p obj && cd obj && g++ -c ../src/*.cc
