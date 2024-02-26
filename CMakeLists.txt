cmake_minimum_required(VERSION 3.25)
project(HasInfluence)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_executable(HasInfluence main.cpp
        main.cpp)


