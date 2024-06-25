cmake_minimum_required(VERSION 3.28)
project(FirstComeFirstServe_CPUScheduling C)

set(CMAKE_C_STANDARD 11)

add_executable(FirstComeFirstServe_CPUScheduling main.c
        FCFS.c
        FCFS.h)
