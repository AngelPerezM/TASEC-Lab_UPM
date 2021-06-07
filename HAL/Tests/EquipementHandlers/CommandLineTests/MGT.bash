#!/bin/bash
h2d(){
	[ -z "$1" -o "$1" = "-h" ] && echo "h2d: Converts HEX to decimal" && return 0
	INPUT=`echo "${@^^}" | sed 's/^0X//'`  # uppercase
	x=`echo "ibase=16; obase=A; $INPUT" | bc`
        [ "$x" -gt 32767 ] && ((x=x-65536))
        echo $x
}

i2c_address=0x1C
sensitivity=0.14

echo "SOFT reset..."
i2cset -y 1 $i2c_address 0x21 0x04 b
sleep 1

echo "Setting Offsets to 0:"
i2cset -y 1 $i2c_address 0x05 0x00 b
i2cset -y 1 $i2c_address 0x06 0x00 b
i2cset -y 1 $i2c_address 0x07 0x00 b
i2cset -y 1 $i2c_address 0x08 0x00 b
i2cset -y 1 $i2c_address 0x09 0x00 b
i2cset -y 1 $i2c_address 0x0A 0x00 b

echo "Checking WHO_AM_I"
who=`i2cget -y 1 $i2c_address 0x0F b`
[ $who = 0x3d  ] && echo "  OK" || echo "  NOK"

# CTRL_REG_1_M:
# 1101 0000, ODR: 10 Hz, HPMode for X and Y, temp compensation.
i2cset -y 1 $i2c_address 0x20 0xD0 b
# CTRL_REG_2_M:
# 0000 0000, FS: +- 4 gauss.
i2cset -y 1 $i2c_address 0x21 0x00 b
# CTRL_REG_3_M:
# 0000 0001, I2C enabled, continuous-conversion mode
i2cset -y 1 $i2c_address 0x22 0x00 b
# CTRL_REG_4_M:
# 0000 1000, Little endian, HPMode for Z
i2cset -y 1 $i2c_address 0x23 0x08 b
# CTRL_REG_5_M:
# 0100 0000, NOT Fast Read, Block data update
i2cset -y 1 $i2c_address 0x24 0x40 b

while true
do
  xr=`i2cget -y 1 $i2c_address 0x28 w`;
  xr=`h2d $xr`
  x=$( bc -l <<< "$xr*$sensitivity")
  yr=`i2cget -y 1 $i2c_address 0x2A w`;
  yr=`h2d $yr`
  y=$( bc -l <<< "$yr*$sensitivity")
  zr=`i2cget -y 1 $i2c_address 0x2C w`;
  zr=`h2d $zr`
  z=$( bc -l <<< "$zr*$sensitivity")
  echo "[$xr, $yr, $zr] raw    [$x, $y, $z] mgauss"
  sleep 1
done
