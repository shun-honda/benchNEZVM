#!/bin/sh
DATADIR=input
BYTECODE=mininez2
VMDIR=../MiniNez2/build

make -C $VMDIR clean
make -C $VMDIR

echo "parse jawiki-index"
./$VMDIR/mininez -p $BYTECODE/utf8.nzc -i $DATADIR/jawiki-20150512-pages-articles-multistream-index.txt

echo "\nparse earthquake.geojson\n"
./$VMDIR/mininez -p $BYTECODE/json.nzc -i input/earthquake.geojson

echo "\nparse xmark5m.xml\n"
./$VMDIR/mininez -p $BYTECODE/xml.nzc -i input/xmark5m.xml


echo "\nparse earthquake.csv\n"
./$VMDIR/mininez -p $BYTECODE/my_csv.nzc -i input/earthquake.csv

echo "\nparse test.syslog\n"
./$VMDIR/mininez -p $BYTECODE/syslog.nzc -i input/test.syslog

echo "\nparse enron\n"
./$VMDIR/mininez -p $BYTECODE/email.nzc -i  input/enron.txt
