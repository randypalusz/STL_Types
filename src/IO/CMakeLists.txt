cmake_minimum_required(VERSION 3.10)

set(This IO)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  IO.hpp
)

set(Sources
  IO.cpp
)

# making an executable from the same file tests are being run on causes the tests
# to not actually run...

# add_executable(IO.cc IO.cpp)

add_library(${This} STATIC ${Sources} ${Headers})
target_include_directories(${This} PUBLIC ./)

