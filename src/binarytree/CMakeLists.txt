cmake_minimum_required(VERSION 3.10)

set(This BinaryTree)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
	RTreeElement.hpp
	RBinaryTree.hpp
)

set(Sources
	RBinaryTree.cpp
)

# making an executable from the same file tests are being run on causes the tests
# to not actually run...

add_executable(RBinaryTree.cc RBinaryTree.cpp RBinaryTree.cc)

add_library(${This} STATIC ${Sources} ${Headers})
target_include_directories(${This} PUBLIC ./)

