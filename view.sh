#!/bin/bash

shopt -s nullglob
cd ${1:-.}
for i in `ls -d */`; do
	arr=(${i}*_?.jpg ${i}*_??.jpg)
	if (( ${#arr[@]} == 0 )); then arr=(${i}*.jpg); fi
	until viewer.x -i ${arr[*]}; do
		result=$?
		if ((result == 255)); then break 2
		else
			image.x ${arr[$result]}
			unset '${arr[$result]}'
		fi
	done
	trash $i
done
