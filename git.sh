#!/bin/bash

if [ ! wget -q --spider http://google.com ]; then exit 1; fi
cd ~/Programming
for i in `ls -d */`; do
	i=${i%/}
	cd $i
	echo $i
	for j in find . -size +3M; do
		if [[ `git check-ignore $j` == "" ]]; then echo $j >> .gitignore; fi
	done
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
	if ! git rev-parse --abbrev-ref --symbolic-full-name @{u}; then
		if ! git branch --set-upstream-to=origin/$i; then 
			git push --set-upstream origin $i
		fi
	fi
	if [[ `git status | sed -En '/커밋만큼 앞에 있습니다/p'` != "" ]]; then
		git push --all
	fi
	cd ..
done
