#!/bin/bash

a=$(ls 099 | wc)
read -a aaa <<< $a
echo ${aaa[0]}
