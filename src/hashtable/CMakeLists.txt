cmake_minimum_required(VERSION 3.10)

set(This Hash)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  RHashObject.hpp
  RHashTable.hpp
)

set(Sources
  RHashTable.cpp
)

# making an executable from the same file tests are being run on causes the tests
# to not actually run...

add_executable(RHashTable.cc RHashTable.cpp RHashTable.cc)

add_library(${This} STATIC ${Sources} ${Headers})
target_include_directories(${This} PUBLIC ./)

