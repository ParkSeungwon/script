#!/bin/bash

if [ ! wget -q --spider http://google.com ]; then exit 1; fi #check internet available
cd ~/Programming
for i in `ls -d */`; do
	cd $i
	echo ------------------------------- $i -------------------------------------
	autocommit.sh
	cd ..
done
