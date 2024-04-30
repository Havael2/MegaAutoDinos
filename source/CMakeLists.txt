# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(MegaAutoDinos C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MegaAutoDinos megaAutoDinos.c)
