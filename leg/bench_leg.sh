#!/bin/sh

gcc -std=c99 -g -DNDEBUG csv.leg.c -o csv -O2
gcc -std=c99 -g -DNDEBUG syslog.leg.c -o syslog -O2
gcc -std=c99 -g -DNDEBUG json.leg.c -o json -O2
gcc -std=c99 -g -DNDEBUG xml.leg.c -o xml -O2

echo "\ncsv\n"
./csv ../input/earthquake.csv

echo "\nsyslog\n"
./syslog ../input/test.syslog

echo "\njson\n"
./json ../input/earthquake.geojson

echo "\nxml\n"
./xml ../input/xmark5m.xml
