cmake_minimum_required(VERSION 3.13)
project(HW3)

set(CMAKE_CXX_STANDARD 98)

add_executable(HW3
        Definitions.h
        Zoo.h  Zoo.cpp
        Animal.h Animal.cpp
        Lion.cpp Lion.h
        Duck.cpp Duck.h
        Proboscidea.cpp Proboscidea.h
        Mammoth.cpp Mammoth.h
        Elephant.cpp Elephant.h


       main.cpp )

