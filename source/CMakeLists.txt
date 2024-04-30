# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(MegaAutoDinos C)

add_executable(MegaAutoDinos megaAutoDinos.c)

add_library(pilhadinos INTERFACE pilhadinos.h)

target_link_libraries(MegaAutoDinos PUBLIC pilhadinos)
