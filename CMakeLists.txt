cmake_minimum_required(VERSION 3.18)
project(HasInfluence)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(HasInfluence main.cpp
        features.h)