cmake_minimum_required(VERSION 3.28)
project(myStack C)

set(CMAKE_C_STANDARD 11)

add_executable(myStack main.c
        StackArray.c
        StackArray.h
        StackLinkedList.c
        StackLinkedList.h)
