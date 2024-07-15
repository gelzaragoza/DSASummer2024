cmake_minimum_required(VERSION 3.28)
project(Graphs C)

set(CMAKE_C_STANDARD 11)

add_executable(Graphs main.c
        Adjaceny_Matrix.c
        Adjacency_Matrix.h)
