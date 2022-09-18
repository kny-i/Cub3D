#!/bin/bash

kill ./cub3d

while true
do
    leaks -q `ps | grep ./cub3d | awk '{print $1}'`
    leaks -q 94987
    sleep 2
done

