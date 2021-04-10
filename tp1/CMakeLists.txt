cmake_minimum_required(VERSION 3.19)
project(tp1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tp1
        bitFieldsExample.h
        card.h
        date.h
        main.cpp
        word.h)
