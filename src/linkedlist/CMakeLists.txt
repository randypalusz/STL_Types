cmake_minimum_required(VERSION 3.10)

set(This LinkedList)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
  RListObject.hpp
  RLinkedList.hpp
)

set(Sources
  RLinkedList.cpp
)

# making an executable from the same file tests are being run on causes the tests
# to not actually run...

add_executable(RLinkedList.cc RLinkedList.cpp RLinkedList.cc)

add_library(${This} SHARED ${Sources} ${Headers})
target_include_directories(${This} PUBLIC ./)

