cmake_minimum_required(VERSION 3.13)
project(petrol_station)

set(CMAKE_CXX_STANDARD 14)

add_executable(petrol_station main.cpp car.cpp station.cpp car.h station.h)