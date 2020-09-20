cmake_minimum_required(VERSION 3.17)
project(myFiveChess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(myFiveChess
        draw.cpp
        draw.h
        main.cpp play.cpp)
