cmake_minimum_required(VERSION 2.6)
project(mushroom)
add_executable(mushroom mushroom.c
                        samples.c)
include_directories("${PROJECT_BINARY_DIR}")
