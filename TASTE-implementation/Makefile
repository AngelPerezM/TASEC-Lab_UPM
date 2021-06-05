KAZOO?=kazoo
# Here you can specify custom compiler/linker flags, and add folders containing
# external code you want to compile and link for a specific partition.
# Use upper case for the partition name:
# export <PARTITIONNAME>_USER_CFLAGS=...
# export <PARTITIONNAME>_USER_LDFLAGS=...
# export <PARTITIONNAME>_EXTERNAL_SOURCE_PATH=
#

ROOT_DIR:=$(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))/..
XCOMP_DIR=$(ROOT_DIR)/RPI_rootfs_v3
B2S_DIR=$(ROOT_DIR)/HAL

export RPI_PARTITION_1_USER_CFLAGS=-v --sysroot=$(XCOMP_DIR) -I$(B2S_DIR)/include
export RPI_PARTITION_1_USER_LDFLAGS=-v --sysroot=$(XCOMP_DIR) -L$(B2S_DIR)/lib \
    				    -lgps -lm -Wl,--sysroot,$(XCOMP_DIR)\
				    -l:EquipementHandlers/equipementHandlers.a -l:Utils/utils.a\
				    -l:BusHandlers/busHandlers.a -lpigpiod_if2


export RPI_PARTITION_2_USER_CFLAGS=-v --sysroot=$(XCOMP_DIR) -I$(B2S_DIR)/include
export RPI_PARTITION_2_USER_LDFLAGS=-v --sysroot=$(XCOMP_DIR) -L$(B2S_DIR)/lib \
    				    -lgps -lm -Wl,--sysroot,$(XCOMP_DIR)\
				    -l:EquipementHandlers/equipementHandlers.a -l:Utils/utils.a\
				    -l:BusHandlers/busHandlers.a -lpigpiod_if2

#export RPI_PARTITION_EXTERNAL_SOURCE_PATH=$(B2S_DIR)/EquipementHandlers/source/:$(B2S_DIR)/Utils/source

all:	c

c:	work/glue_built
	$(MAKE) -C work

# Simulation target (experimental)
simu:	InterfaceView.aadl DeploymentView.aadl DataView.aadl ConcurrencyView_Properties.aadl
	$(KAZOO) -t SIMU --glue --gw
	$(MAKE) -C work

skeletons:
	$(MAKE) work/skeletons_built

work/skeletons_built:	InterfaceView.aadl DataView.aadl
	$(KAZOO) --gw -o work
	$(MAKE) -C work dataview
	touch $@

work/glue_built:	InterfaceView.aadl DeploymentView.aadl DataView.aadl ConcurrencyView_Properties.aadl
	$(KAZOO) -p --glue --gw -o work
	touch $@

clean:
	rm -rf work/build
	rm -f work/glue_built work/skeletons_built
	find work -type d -name "wrappers" -exec rm -rf {} +
	find work -type d -name "*_GUI" -exec rm -rf {} +

.PHONY: clean skeletons c simu

