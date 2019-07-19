#!/bin/bash

cd ~/Programming
for i in `ls -d */`; do
	i=${i%/}
	cd $i
	echo $i
	if [ ! -d .git ]; then 
		git init; 
		if [ ! -f README.md ]; then echo "# $i" > README.md; fi
		curl -u "ParkSeungwon:cockcodk0" https://api.github.com/user/repos -d '{"name":"'$i'"}'
		git remote add origin git@github.com:ParkSeungwon/${i}.git
	fi

	if [[ `git status | sed -En '/커밋할 사항 없음, 작업 폴더 깨끗함/p'` == "" ]]; then
		git add .
		git commit -m"`date` autocommit"
	fi
	git push --all
	cd ..
done
