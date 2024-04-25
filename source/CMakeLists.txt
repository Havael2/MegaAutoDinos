# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(MegaAutoDinos C)

add_subdirectory(pilhadinos)

target_include_directories(MegaAutoDinos PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MegaAutoDinos"
                          )

add_executable(MegaAutoDinos megaAutoDinos.c)

target_link_libraries(MegaAutoDinos PUBLIC pilhadinos)
