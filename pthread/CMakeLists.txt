cmake_minimum_required(VERSION 3.10)
project(pthread C)

set(CMAKE_C_STANDARD 99)
LINK_LIBRARIES(-lpthread)
add_executable(pthread main.c)