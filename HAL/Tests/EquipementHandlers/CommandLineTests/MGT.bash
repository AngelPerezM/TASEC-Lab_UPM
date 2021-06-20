#!/bin/bash
h2d(){
	[ -z "$1" -o "$1" = "-h" ] && echo "h2d: Converts HEX to decimal" && return 0
	INPUT=`echo "${@^^}" | sed 's/^0X//'`  # uppercase
	x=`echo "ibase=16; obase=A; $INPUT" | bc`
        [ "$x" -gt 32767 ] && ((x=x-65536))
        echo $x
}

i2c_address=0x1C
sensitivity=0.58

echo "SOFT reset..."
i2cset -y 1 $i2c_address 0x21 0x04 b
sleep 1

echo "Setting Offsets to 0:"
i2cget -y 1 $i2c_address 0x05 #0x00 b
i2cget -y 1 $i2c_address 0x06 #0x00 b
i2cget -y 1 $i2c_address 0x07 #0x00 b
i2cget -y 1 $i2c_address 0x08 #0x00 b
i2cget -y 1 $i2c_address 0x09 #0x00 b
i2cget -y 1 $i2c_address 0x0A #0x00 b

echo "Checking WHO_AM_I"
who=`i2cget -y 1 $i2c_address 0x0F b`
[ $who = 0x3d  ] && echo "$who=0x3d  OK" || echo "$who!=0x3d  NOK"

# CTRL_REG_1_M:
# 1101 1100, ODR: 10 Hz, HPMode for X and Y, temp. compensation.
i2cset -y -r 1 $i2c_address 0x20 0xDC b
# CTRL_REG_2_M:
# 0110 0000, FS: +- 16 gauss.
i2cset -y -r 1 $i2c_address 0x21 0x60 b
# CTRL_REG_3_M:
# 0000 0000, I2C enabled, continuous-conversion mode
i2cset -y -r 1 $i2c_address 0x22 0x00 b
# CTRL_REG_4_M:
# 0000 1000, Little endian, HPMode for Z
i2cset -y -r 1 $i2c_address 0x23 0x08 b
# CTRL_REG_5_M:
# 0100 0000, NOT Fast Read, Block data update
i2cset -y -r 1 $i2c_address 0x24 0x40 b

while true
do
  xb=`i2cget -y 1 $i2c_address 0x28 w`;
  xr=`h2d $xb`
  x=$( bc -l <<< "$xr*$sensitivity")
  yb=`i2cget -y 1 $i2c_address 0x2A w`;
  yr=`h2d $yb`
  y=$( bc -l <<< "$yr*$sensitivity")
  zb=`i2cget -y 1 $i2c_address 0x2C w`;
  zr=`h2d $zb`
  z=$( bc -l <<< "$zr*$sensitivity")
  echo "[$xb, $yb, $zb] bin    [$xr, $yr, $zr] raw   [$x, $y, $z] mgauss"
  echo "$xr, $yr, $zr, $x, $y, $z" &>> ./log_mgt.csv

  sleep 0.5
done
