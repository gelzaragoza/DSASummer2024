cmake_minimum_required(VERSION 3.28)
project(Sets C)

set(CMAKE_C_STANDARD 11)

add_executable(Sets main.c
        SetArray.h
        SetArray.c)
