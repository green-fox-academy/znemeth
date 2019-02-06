cmake_minimum_required(VERSION 3.13)
project(instruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(instruments main.cpp instrument.cpp StringedInstrument.cpp)