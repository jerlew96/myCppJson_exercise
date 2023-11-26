cmake_minimum_required(VERSION 3.26)
project(MyCppJson_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyCppJson_test main.cpp
        json/Json.h
        json/Json.cpp
        json/Parser.h
        json/Parser.cpp)
