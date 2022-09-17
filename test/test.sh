#!/bin/bash

red='\033[0;31m'
green='\033[32m'
no='\033[0m'

execpath="../src/cub3d"

$execpath ../test/normal/00_simple_20_13.cub
echo -e $green"[ok case]"$no

$execpath ../test/ok/spact_direction.cub
echo -e $green"[space direction format case]"$no

$execpath ../test/ok/space_FC.cub
echo -e $green"[space F C format case]"$no

$execpath ../test/ok/dup.cub
echo -e $green"[Priority is given to the one below]"$no
