cmake_minimum_required(VERSION 3.13)
project(flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(flyable main.cpp Flyable.cpp Vehicle.cpp Helicopter.cpp Bird.cpp Animal.cpp)