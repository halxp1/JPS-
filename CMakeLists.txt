cmake_minimum_required(VERSION 3.10)
project(test5)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)
aux_source_directory(. DIR_SRCS)

add_executable(test5 ${DIR_SRCS})