#!/bin/bash

cd ${1:-.}
old=$IFS
IFS=$'\n'
while [ :: ]; do
	var=`ls -r -1 | head -n 1 | sed -E 's/(.*?_[0-9]{3}_).*/\1/'`
	viewer.x -i ${var}* && trash ${var}* || break
done
IFS="$old"
