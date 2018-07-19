cmake_minimum_required(VERSION 3.10)
project(extern_static C)

set(CMAKE_C_STANDARD 99)

add_executable(extern_static main.c function.c)