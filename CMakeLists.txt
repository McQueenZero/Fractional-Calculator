cmake_minimum_required(VERSION 3.16)
project(FractionalCalculator)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -finput-charset=GBK -fexec-charset=UTF-8")

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(inc)

add_executable(FractionalCalculator main.cpp ${SOURCE_FILES} ${SOURCES})
