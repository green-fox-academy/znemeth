cmake_minimum_required(VERSION 3.13)
project(aircraft_carrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(aircraft_carrier main.cpp Aircraft.cpp Carrier.cpp)