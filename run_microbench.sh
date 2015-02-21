#!/bin/sh
DATADIR=microbench/input
BYTECODE=microbench_bytecode
VMDIR=../peg4d-java/pegvm/build
make -C $VMDIR clean
make -C $VMDIR

echo "\nRepChoice\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/RepChoice.bin -i $DATADIR/RepChoice.txt

echo "\nRepLine\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/RepLine.bin -i $DATADIR/RepLine.txt

echo "\nSlowChoice\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/SlowChoice.bin -i $DATADIR/SlowChoice.txt

echo "\nStringChoice\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/StringChoice.bin -i $DATADIR/StringChoice.txt

echo "\nStringLiteral\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/StringLiteral.bin -i $DATADIR/StringLiteral.txt

echo "\nZeroMoreAny\n"
./$VMDIR/pegvm -t stat -p $BYTECODE/ZeroMoreAny.bin -i $DATADIR/StringLiteral.txt
