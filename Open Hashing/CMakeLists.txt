cmake_minimum_required(VERSION 3.28)
project(Hashing C)

set(CMAKE_C_STANDARD 11)

add_executable(Hashing main.c
        OpenHashing.c
        OpenHashing.h
)
