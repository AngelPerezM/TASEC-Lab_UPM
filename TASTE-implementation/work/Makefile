# MAKEFILE_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_PATH   := $(lastword $(MAKEFILE_LIST))
TOOL_INST       := $(shell taste-config --prefix)
OUTDIR          := $(dir $(MAKEFILE_PATH))
ASN1_FILES      := ../DataView.asn ${TOOL_INST}/share/taste-types/taste-types.asn
CP_FILES        := ../work/anemometer/CPP/Context-anemometer.asn ../work/datapool/CPP/Context-datapool.asn ../work/gpsreader/CPP/Context-gpsreader.asn ../work/heater1/CPP/Context-heater1.asn ../work/heater2/CPP/Context-heater2.asn ../work/pressuresensors/CPP/Context-pressuresensors.asn ../work/pt1000sensors/CPP/Context-pt1000sensors.asn ../work/tc74sensors/CPP/Context-tc74sensors.asn      # Context parameters
DATAVIEW_PATH   := ${OUTDIR}/dataview
DATAVIEW_UNIQ   := ${DATAVIEW_PATH}/dataview-uniq.asn
DATAVIEW_ACN    := ${DATAVIEW_PATH}/dataview-uniq.acn
DATAVIEW_AADLV1 := ${DATAVIEW_PATH}/dataview_aadlv1.aadl
DATAVIEW_AADLV2 := ${DATAVIEW_PATH}/dataview_aadlv2.aadl
TASTE_SHARED_TYPES?=${TOOL_INST}/share/SharedTypes

# Project cache folder is used to speed up all ASN.1-related processing
export PROJECT_CACHE=${HOME}/.taste_AST_cache

all:	build-default

# Generate the language-specific data view needed before editing user code
dataview:	dataview/C/built dataview/Ada/built
	# Copy the dataview to SDL function HeatTransferLab (no context parameters)
	cp -u ${DATAVIEW_UNIQ} heattransferlab/SDL/src
	# Copy the dataview to SDL function Thermostat (no context parameters)
	cp -u ${DATAVIEW_UNIQ} thermostat/SDL/src

# Generate the complete dataview, including Python bindings if there is a GUI
${DATAVIEW_PATH}/built:	dataview dataview/Python/built
	touch $@

# Build based on the deployment view
build-default:	aadl2glueC build/system_config.h ${DATAVIEW_PATH}/built build/deploymentview_final/Makefile
	$(MAKE) -j -C build -f Makefile.taste

# Rule to invoke Ocarina (generation of POHI middleware code)
build/deploymentview_final/Makefile:	build/main.aadl ${DATAVIEW_AADLV2} ../ConcurrencyView_Properties.aadl
	cd build ; ocarina -x main.aadl

# Optionally hold thread priorities, offset, stack size. Create if not present
../ConcurrencyView_Properties.aadl:
	touch $@

# Optionally manage SQL Database (run taste-create-database to enable)
sql_db/DV.py:
	mkdir -p sql_db && touch $@

# Create dataview-uniq.asn by concatenating all asn1 input files
${DATAVIEW_UNIQ}:	${ASN1_FILES}
	mkdir -p ${PROJECT_CACHE} && mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# Create dataview-uniq.acn by concatenating all input files
${DATAVIEW_ACN}:	../DataView.acn
	mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# system_config.h is used to filter out non-needed ASN.1 encoder/decoders
build/system_config.h:	$(wildcard */*/wrappers/*_system_config.h)
	cat $^ > $@

#  Call DMT/aadl2glueC to generate glue code from the mini-cv.aadl files
aadl2glueC:	anemometer/CPP/wrappers/aadl2glueC_built datalogger/CPP/wrappers/aadl2glueC_built datamonitor/CPP/wrappers/aadl2glueC_built datapool/CPP/wrappers/aadl2glueC_built gpsreader/CPP/wrappers/aadl2glueC_built gui/GUI/wrappers/aadl2glueC_built heater1/CPP/wrappers/aadl2glueC_built heater2/CPP/wrappers/aadl2glueC_built heattransferlab/SDL/wrappers/aadl2glueC_built i2cbusreader/CPP/wrappers/aadl2glueC_built imu/CPP/wrappers/aadl2glueC_built pressuresensors/CPP/wrappers/aadl2glueC_built prettyformat/CPP/wrappers/aadl2glueC_built pt1000sensors/CPP/wrappers/aadl2glueC_built tc/CPP/wrappers/aadl2glueC_built tc74sensors/CPP/wrappers/aadl2glueC_built thermostat/SDL/wrappers/aadl2glueC_built tm/CPP/wrappers/aadl2glueC_built

# Build dataview.aadl in AADLv1 format, used by DMT to generate glue code
${DATAVIEW_AADLV1}: ${DATAVIEW_UNIQ}
	asn2aadlPlus  $< $@

# Build dataview.aadl in AADLv2 format, used by Ocarina to generate glue code
${DATAVIEW_AADLV2}: ${DATAVIEW_UNIQ}
	asn2aadlPlus --aadlv2  $< $@

anemometer/CPP/wrappers/aadl2glueC_built: anemometer/CPP/wrappers/anemometer_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

datalogger/CPP/wrappers/aadl2glueC_built: datalogger/CPP/wrappers/datalogger_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

datamonitor/CPP/wrappers/aadl2glueC_built: datamonitor/CPP/wrappers/datamonitor_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

datapool/CPP/wrappers/aadl2glueC_built: datapool/CPP/wrappers/datapool_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

gpsreader/CPP/wrappers/aadl2glueC_built: gpsreader/CPP/wrappers/gpsreader_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

gui/GUI/wrappers/aadl2glueC_built: gui/GUI/wrappers/gui_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

heater1/CPP/wrappers/aadl2glueC_built: heater1/CPP/wrappers/heater1_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

heater2/CPP/wrappers/aadl2glueC_built: heater2/CPP/wrappers/heater2_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

heattransferlab/SDL/wrappers/aadl2glueC_built: heattransferlab/SDL/wrappers/heattransferlab_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

i2cbusreader/CPP/wrappers/aadl2glueC_built: i2cbusreader/CPP/wrappers/i2cbusreader_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

imu/CPP/wrappers/aadl2glueC_built: imu/CPP/wrappers/imu_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

pressuresensors/CPP/wrappers/aadl2glueC_built: pressuresensors/CPP/wrappers/pressuresensors_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

prettyformat/CPP/wrappers/aadl2glueC_built: prettyformat/CPP/wrappers/prettyformat_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

pt1000sensors/CPP/wrappers/aadl2glueC_built: pt1000sensors/CPP/wrappers/pt1000sensors_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

tc/CPP/wrappers/aadl2glueC_built: tc/CPP/wrappers/tc_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

tc74sensors/CPP/wrappers/aadl2glueC_built: tc74sensors/CPP/wrappers/tc74sensors_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

thermostat/SDL/wrappers/aadl2glueC_built: thermostat/SDL/wrappers/thermostat_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

tm/CPP/wrappers/aadl2glueC_built: tm/CPP/wrappers/tm_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@


# Compile the ASN.1 models in C
dataview/C/built: ${DATAVIEW_UNIQ} ${DATAVIEW_ACN} ${CP_FILES}
	mkdir -p $(dir $@)
	# asn2dataModel does not take the ACN files, and only calls asn1.exe
	# asn2dataModel -o $(dir $@) -toC ${DATAVIEW_UNIQ} ${DATAVIEW_ACN}
	mono $(shell which asn1.exe) -typePrefix asn1Scc -equal -fp AUTO -o $(dir $@) -c -uPER -ACN $^
	cp ${TOOL_INST}/share/AutoGUI/debug_messages.? dataview/C
	cp ${TOOL_INST}/share/AutoGUI/timeInMS.? dataview/C
	cd dataview/C && msgPrinter ../dataview-uniq.asn
	cd dataview/C && msgPrinterASN1 ../dataview-uniq.asn
	touch $@

# Compile the ASN.1 models in Python for the autogenerated GUIs
dataview/Python/built:	dataview/C/built gui/GUI/wrappers/aadl2glueC_built sql_db/DV.py
	mkdir -p $(dir $@)
	asn2dataModel -o $(dir $@) -toPython ${DATAVIEW_UNIQ}
	$(MAKE) -C dataview/Python -f Makefile.python
	cp dataview/Python/* gui/GUI/wrappers/python
	cp dataview/C/timeInMS.[ch] dataview/C/debug_messages.c gui/GUI/wrappers/python
	cd gui/GUI/wrappers/python && \
	   gcc -g -fPIC -c `python-config --cflags`  gui_api.c ../../src/queue_manager.c timeInMS.c debug_messages.c -I. -I../../src && \
	   gcc -g -shared -o PythonAccess.so gui_api.o queue_manager.o timeInMS.o debug_messages.o `python-config --ldflags` -lrt
	mkdir -p binaries/gui_GUI
	cp -f gui/GUI/wrappers/python/* binaries/gui_GUI
	cp -f gui/GUI/wrappers/*.py binaries/gui_GUI
	cp -f gui/GUI/wrappers/*.ui binaries/gui_GUI
	echo "errCodes = \\" >> binaries/gui_GUI/datamodel.py
	taste-asn1-errCodes binaries/gui_GUI/dataview-uniq.h >> binaries/gui_GUI/datamodel.py
	if [ -f sql_db/db.info ]; then cd binaries/gui_GUI && ln -fs ../../sql_db; fi
	# User can edit at will the customisable user widgets python module:
	cp -u ${TOOL_INST}/share/AutoGUI/UserWidgets.py binaries/gui_GUI
	#  Interface view must be placed in the gui folder to allow replaying MSCs
	cp -u ../InterfaceView.aadl binaries/gui_GUI
	touch $@

dataview/Ada/built: ${DATAVIEW_UNIQ} ${CP_FILES}
	mkdir -p $(dir $@)
	asn2dataModel -allboards -o $(dir $@) -toAda $^
	touch $@
	cd dataview/Ada && rm -f gnat.cfg GPS_project.gpr IgnoredExaminerWarnings.wrn runSpark.sh

clean:
	rm -rf binaries dataview
	$(MAKE) -C build -f Makefile.taste clean

.PHONY: clean simu compile-all-linux function-instances-linux function-types-linux build-default dataview build-rtems-ada dataview
