cmake_minimum_required(VERSION 2.6)
project(mushroom)
add_executable(mushroom mushroom.c
                        samples.c
                        image.c)
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -Werr -g")
