#!/bin/bash

while true
do
    #leaks -q `ps | grep ./cub3d | awk '{print $1}'`
    leaks -q 21738
    sleep 2
done

