cmake_minimum_required(VERSION 3.22)
project(cub3D)

set(CMAKE_CXX_STANDARD 14)

include_directories(training)
include_directories(srcs)

add_executable(cub3D
        training/cub.h
        training/main.c
        training/Makefile
        srcs/cub
        srcs/cub3d.h
        srcs/key.c
        srcs/main.c)
