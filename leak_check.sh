#!/bin/bash

ps

while true
do
    leaks -q `ps | grep './cub3d' | grep 'ok' | awk '{print $1}'`
    sleep 1
done

