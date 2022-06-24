cmake_minimum_required(VERSION 3.22)
project()

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        basic.h
        empty.cpp
        empty.h
        fox.cpp
        fox.h
        grass.cpp
        grass.h
        human.cpp
        human.h
        living.cpp
        living.h
        main.cpp
        rabbit.cpp
        rabbit.h
        scene.cpp
        scene.h
        world.cpp
        world.h
        )