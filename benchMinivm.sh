#!/bin/sh
DATADIR=input
BYTECODE=minivmByteCode/nonOpt
BYTECODEOPT=minivmByteCode/opt
VMDIR=../MiniNezvm/src/mini_instruction_vm/build
OPTVMDIR=../MiniNezvm/src/mini_instruction_opt_vm/build

echo "\nunoptimized bench data\n"

make -C $VMDIR clean
make -C $VMDIR
echo "\nparse earthquake.geojson\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/json.bin -i $DATADIR/earthquake.geojson

echo "\nparse benchmark4.json\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/json.bin -i $DATADIR/benchmark4.json

echo "\nparse citys.json\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/json.bin -i $DATADIR/citys.json

echo "\nparse xmark5m.xml\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/xml.bin -i $DATADIR/xmark5m.xml

echo "\nparse geometry_base.xml\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/xml.bin -i $DATADIR/geometry_base.xml

echo "\nparse 01HOKKAI_ROME.CSV\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/csv.bin -i $DATADIR/01HOKKAI_ROME.CSV

echo "\nparse earthquake.csv\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/csv.bin -i $DATADIR/earthquake.csv

echo "\nparse test.syslog\n"
./$VMDIR/nezvm -t stat -p $BYTECODE/syslog.bin -i $DATADIR/test.syslog

echo "\noptimized bench data\n"

make -C $OPTVMDIR clean
make -C $OPTVMDIR
echo "\nparse earthquake.geojson\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/json.bin -i $DATADIR/earthquake.geojson

echo "\nparse benchmark4.json\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/json.bin -i $DATADIR/benchmark4.json

echo "\nparse citys.json\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/json.bin -i $DATADIR/citys.json

echo "\nparse xmark5m.xml\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/xml.bin -i $DATADIR/xmark5m.xml

echo "\nparse geometry_base.xml\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/xml.bin -i $DATADIR/geometry_base.xml

echo "\nparse 01HOKKAI_ROME.CSV\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/csv.bin -i $DATADIR/01HOKKAI_ROME.CSV

echo "\nparse earthquake.csv\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/csv.bin -i $DATADIR/earthquake.csv

echo "\nparse test.syslog\n"
./$OPTVMDIR/nezvm -t stat -p $BYTECODEOPT/syslog.bin -i $DATADIR/test.syslog