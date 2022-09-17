#!/bin/bash

while true
do
    leaks -q `ps | grep ./minishell | awk '{print $1}'`
done

