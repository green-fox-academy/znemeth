cmake_minimum_required(VERSION 3.13)
project(GFA)

set(CMAKE_CXX_STANDARD 14)

add_executable(GFA main.cpp cohort.cpp mentor.cpp person.cpp sponsor.cpp student.cpp)