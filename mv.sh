#!/bin/bash

for i in `ls`; do
	mv "$i" "${i#언더그라운드}";
done

