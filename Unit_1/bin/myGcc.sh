#!/bin/bash
#定制化一下gcc命令
if [ ${1:0-2} == ".c" ]; then
	gcc $1 -o ../bin/${1%.*}.sh
elif [ ${1:0-4} == ".cpp" ]; then	
	g++ $1 -o ../bin/${1%.*}.sh
else 
	echo "只能编译.c/.cpp文件"
fi
