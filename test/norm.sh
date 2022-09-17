#!/bin/bash

red='\033[0;31m'
green='\033[32m'
no='\033[0m'

norminette ../src/*.c
exit_status=$?
if [ $exit_status -eq 0 ]; then
  echo -e $green"*.c file in srcs are norm ok!"$no
else
  echo -e $red"*.c file in srcs are norm error!"$no
fi

