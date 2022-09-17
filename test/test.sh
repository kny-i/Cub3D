#!/bin/bash

red='\033[0;31m'
green='\033[32m'
no='\033[0m'

execpath="../src/cub3d"

$execpath ../test/normal/00_simple_20_13.cub
echo -e $green"[ok case]"$no


#echo -e ${green}"<OK TEST>"${no}
#make -C ../src aok ;
#make -C ../src bok ;
#make -C ../src cok ;
#make -C ../src dok ;
#make -C ../src eok ;
#make -C ../src fok
#echo -e ${red}"<KO TEST>"${no}
#make -C ../src ako ;
#make -C ../src bko ;
#make -C ../src cko ;
#make -C ../src dko ;
#make -C ../src eko ;
#make -C ../src fko ;
#make -C ../src gko ;
#make -C ../src hko ;
#make -C ../src iko
