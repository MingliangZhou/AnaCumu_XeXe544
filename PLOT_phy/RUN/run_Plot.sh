#!/bin/sh

for ((I1=0;I1<1;I1+=1))
do
root -b -l <<EOF
.L ../Plot.cxx+
Plot()
.q
EOF
done

rm -rf ../*.d
rm -rf ../*.so
