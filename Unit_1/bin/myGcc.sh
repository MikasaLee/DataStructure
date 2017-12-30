#!/bin/bash
#定制化一下gcc命令
gcc $1 -o ../bin/${1%.*}.sh
