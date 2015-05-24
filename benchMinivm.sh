#!/bin/sh
DATADIR=input
BYTECODE=minivmByteCode/nonOpt
BYTECODEOPT=minivmByteCode/opt
VMDIR=../MiniNezVM/src/mini_instruction_vm/build
OPTVMDIR=../MiniNezVM/src/mini_instruction_opt_vm/build

make -C ../MiniNezVM/src/mini_instruction_opt_vm/build clean
make -C ../MiniNezVM/src/mini_instruction_opt_vm/build

echo "parse jawiki-index"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/utf8.nez.bin -i input/jawiki-20150512-pages-articles-multistream-index.txt

echo "\nparse earthquake.geojson\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/json.nez.bin -i input/earthquake.geojson

echo "\nparse xmark5m.xml\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/xml.nez.bin -i input/xmark5m.xml


echo "\nparse earthquake.csv\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/csv.nez.bin -i input/earthquake.csv

echo "\nparse test.syslog\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/syslog.nez.bin -i input/test.syslog

echo "\nparse enron\n"
./../MiniNezVM/src/mini_instruction_opt_vm/build/nezvm -t stat -p minivmByteCode/opt/email.nez.bin -i  input/enron.txt

