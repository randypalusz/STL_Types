cmake_minimum_required(VERSION 3.10)

set(This Example)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  Example.hpp
)

set(Sources
  Example.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
target_include_directories(${This} PUBLIC ./)

