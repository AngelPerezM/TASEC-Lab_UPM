# SDL
#Taste::Active_Interfaces any
#Taste::coordinates 222060 53865 257457 74337
OPENGEODE?=opengeode

all: compile-linux

clean:
	rm -rf obj

edit:
	cd src && $(OPENGEODE) system_structure.pr heattransferlab.pr

# Ada
generate-code:
	mkdir -p code && cd code && \
	   $(OPENGEODE) --taste --toAda ../src/heattransferlab.pr ../src/system_structure.pr && \
	   mv *.gpr ..

compile-linux: generate-code
	   CODE_PATH=code ADA_INCLUDE_PATH=../../../dataview/Ada gprbuild -p -P heattransferlab_ada.gpr

