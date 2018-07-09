cmake_minimum_required(VERSION 3.10)
project(superpipe C)

set(CMAKE_C_STANDARD 99)
LINK_LIBRARIES(-lm)
add_executable(superpipe main.c)