cmake_minimum_required(VERSION 3.28)
project(Graphs_Adjacency_List C)

set(CMAKE_C_STANDARD 11)

add_executable(Graphs_Adjacency_List main.c
        Adjacency_List.c
        Adjacency_List.h)
