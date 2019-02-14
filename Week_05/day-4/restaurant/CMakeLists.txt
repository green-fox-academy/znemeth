cmake_minimum_required(VERSION 3.13)
project(restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(restaurant main.cpp restaurant.cpp employee.cpp waiter.cpp chef.cpp manager.cpp)