#!/bin/bash

cd ${1:-.}
old=$IFS
IFS=$'\n'
for i in `ls -1`; do
	identify "$i" > /dev/null
	if (( $? != 0 )); then echo $i; trash "$i"; fi
done
IFS="$old"
