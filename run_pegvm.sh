#!/bin/sh
DATADIR=input
BYTECODE=bytecodeFast
VMDIR=../peg4d-java/pegvm/build
make -C $VMDIR clean
make -C $VMDIR
echo "\nparse earthquake.geojson\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/json.bin -i $DATADIR/earthquake.geojson

echo "\nparse benchmark4.json\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/json.bin -i $DATADIR/benchmark4.json

echo "\nparse xmark5m.xml\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/xml.bin -i $DATADIR/xmark5m.xml

echo "\nparse nss_cache.c\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/c99.bin -i $DATADIR/nss_cache.c
