cmake_minimum_required(VERSION 3.23)
project(Lab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab7
        calculate.cpp
        calculator.h
        changeToRPN.cpp
        checkUserInput.cpp
        main.cpp
        print_like_LCD.cpp)
