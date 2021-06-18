#!/bin/bash

bins="/home/taste/taste-workspace/b2space/TASTE-implementation/work/binaries"
ip_rpi="192.168.5.2"
ip_hp="192.168.5.3"

cd ${bins}

wait_for_key () {
    echo $1
    while [ true ] ; do
        read -t 3 -n 1
        if [ $? = 0 ] ; then
            break
        fi
    done
}

# 1) RPi:
###############################################################################
if [ -z "$1"  ]; then
    obsw_name="TASEC-LAB.exe"
else
    obsw_name="TASEC-LAB-NO-HTL.exe"
fi

# check if already executing and kill it if true:
obsw_pid=$(ssh pi@${ip_rpi} "pidof ${obsw_name}")
[ -z "${obsw_pid}" ] || ssh pi@${ip_rpi} 'kill ${obsw_pid}'

obsw_pid=$(ssh pi@${ip_rpi} "pidof ${obsw_name}")
if [[ ! -z "${obsw_pid}" ]]; then
    # not empty
    echo "[ERROR] OBSW was already executing and could not be stopped."
    wait_for_key "Press any key to finish."
    exit 1
fi

# start obsw:
ssh pi@${ip_rpi} "~/${obsw_name} &"
obsw_pid=$(ssh pi@${ip_rpi} "pidof ${obsw_name}")
if [[ -z "${obsw_pid}" ]]; then
    # not empty
    echo "[ERROR] Could not start Raspberry Pi program."
    wait_for_key "Press any key to finish."
    exit 1
else
    echo "[INFO] Raspberry Pi program is executing."
fi

# 2) HP:
###############################################################################
./run_x86_partition_partition &
gnd_pid=$!
if [[ -z "${gnd_pid}" ]]; then
    # not empty
    echo "[ERROR] Could not start Graphical User Interface."
    wait_for_key "Press any key to finish."
    exit 1
else
    echo "[INFO] Graphical User Interface is executing."
fi

wait_for_key "Press any key to finish the execution."

kill $obsw_pid
pkill GUI

exit 0
