cmake_minimum_required(VERSION 3.28)
project(CloseHashing C)

set(CMAKE_C_STANDARD 11)

add_executable(CloseHashing main.c
        CloseHashing.h
        CloseHashing.c)
