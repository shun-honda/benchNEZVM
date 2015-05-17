#!/bin/sh
DATADIR=input
BYTECODE=minivmByteCode/nonOpt
BYTECODEOPT=minivmByteCode/opt
VMDIR=../MiniNezVM/src/mini_instruction_vm/build
OPTVMDIR=../MiniNezVM/src/mini_instruction_opt_vm/build

make -C ../MiniNezVM/src/mini_instruction_opt_vm/build clean
make -C ../MiniNezVM/src/mini_instruction_opt_vm/build
echo "\nparse earthquake.geojson\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/json.bin -i input/earthquake.geojson

echo "\nparse benchmark4.json\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/json.bin -i input/benchmark4.json

echo "\nparse citys.json\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/json.bin -i input/citys.json

echo "\nparse xmark5m.xml\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/xml.bin -i input/xmark5m.xml

echo "\nparse geometry_base.xml\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/xml.bin -i input/geometry_base.xml

echo "\nparse 01HOKKAI_ROME.CSV\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/csv.bin -i input/01HOKKAI_ROME.CSV

echo "\nparse earthquake.csv\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/csv.bin -i input/earthquake.csv

echo "\nparse test.syslog\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/syslog.bin -i input/test.syslog