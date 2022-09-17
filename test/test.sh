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

$execpath ../test/ok/dup.cub
echo -e $green"[Priority is given to the one below]"$no

$execpath ../test/ok/jumbled_order.cub
echo -e $green"[order is not important]"$no

$execpath ../test/ok/space_in_map.cub
echo -e $green"[No problem with closed map]"$no

$execpath ../test/ko/not_nbrs.cub
echo -e $red"[not nbrs case]"$no

$execpath ../test/ko/invalid_filename.abc
echo -e $red"[invalid filename case]"$no

$execpath ./test/ko/cub.cub.42
echo -e $red"[invalid filename case]"$no

$execpath ./test/ko/invalid_rgb.cub
echo -e $red"[invalid rgb case]"$no

$execpath
echo -e $red"[invalid argument count case]"$no

$execpath ../test/ok/ok.cub ../test/ok/ok.cub
echo -e $red"[invalid argument count case]"$no

$execpath ../test/ko/invalid_map_char.cub
echo -e $red"[invalid map char]"$no

$execpath ../test/ko/invalid_map_dup_player.cub
echo -e $red"[invalid map duplicate player]"$no

$execpath ../test/ko/invalid_map_not_closed.cub
echo -e $red"[invalid map not closed]"$no

$execpath ../test/ko/invalid_map_player_outside.cub
echo -e $red"[invalid map player outside map]"$no