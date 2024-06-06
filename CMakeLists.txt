cmake_minimum_required(VERSION 3.28)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tetris
        Header.hpp
        main.cpp
        Source.cpp)
