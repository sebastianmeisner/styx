#!/bin/bash

# Create temporary directory
mkdir -p xst/projnav.tmp/
mkdir -p heater_on heater_off main

xst -ifn reconf_main.xst
mv main.ngc main/

for i in 0 1 2 3 4 5 ; do
xst -ifn reconf_heater_$i\_off.xst
mv heater_$i.ngc heater_off/
xst -ifn reconf_heater_$i\_on.xst
mv heater_$i.ngc heater_on/
done;




