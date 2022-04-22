cmake_minimum_required(VERSION 3.20)
project(FractionalCalculator)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(inc)

add_executable(FractionalCalculator main.cpp ${SOURCE_FILES} ${SOURCES})
