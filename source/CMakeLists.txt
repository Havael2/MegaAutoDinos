# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(MegaAutoDinos C)

add_subdirectory(pilhadinos)

add_executable(MegaAutoDinos megaAutoDinos.c)

target_include_directories(MegaAutoDinos PUBLIC
                           "${PROJECT_BINARY_DIR}/pilhadinos"
                          )

target_link_libraries(MegaAutoDinos PUBLIC pilhadinos)
