#!/bin/bash

# Create temporary directory
mkdir -p xst/projnav.tmp/
mkdir -p heater_on heater_off main

# Run synthesis for main circuit
xst -ifn reconf_main.xst
mv main.ngc main/

# Run synthesis for reconfigurable heaters
for i in 0 1 2 3 4 5 ; do
  xst -ifn reconf_heater_$i\_off.xst
  mv heater_$i.ngc heater_off/
  xst -ifn reconf_heater_$i\_on.xst
  mv heater_$i.ngc heater_on/
done;

# Copy  Netlists to planAhead directory
for i in 0 1 2 3 4 5 ; do
  cp --backup=numbered --suffix=backup heater_on/heater_$i.ngc ../planahead/styx_new.srcs/heater_$i\_ins\#heater_$i\_on/imports/heater_on/
  cp --backup=numbered --suffix=backup heater_off/heater_$i.ngc ../planahead/styx_new.srcs/heater_$i\_ins\#heater_$i\_off/imports/heater_off/  
done;

echo "Copying netlists to planahead directory..."
cp --backup=numbered --suffix=backup main/main.ngc ../planahead/styx_new.srcs/sources_1/imports/main/
