cmake_minimum_required(VERSION 3.17)
project(p5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(p5
        English.cpp
        English.h
        p5.cpp
        WordCounter.cpp
        WordCounter.h)
