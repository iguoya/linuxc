cmake_minimum_required(VERSION 3.10)
project(share_memory C)

set(CMAKE_C_STANDARD 99)

add_executable(share_memory_read main.c)
add_executable(share_memory_write share_memory_write.c)