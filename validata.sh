#!/bin/bash
BYTECODE=$1
VMDIR=../peg4d-java/pegvm/build
INFILE=`basename $2`
OUTFILE="parsed_${INFILE}.txt"
DUMPDIR=dump_pego

./$VMDIR/pegvm -t file -p $1 -i $2 -o $OUTFILE > /dev/null 2>&1
javac Validation.java
java Validation $DUMPDIR/$OUTFILE $OUTFILE
rm $OUTFILE