cmake_minimum_required(VERSION 2.8)

project(LoggerTest)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_executable(Test ${DIR_SRCS})
