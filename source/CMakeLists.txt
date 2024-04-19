# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(MegaAutoDinos)

# generate a library from sources
add_library(library pilhadinos.h)

add_executable(MegaAutoDinos megaAutoDinos.c)

target_link_libraries(MegaAutoDinos library)
