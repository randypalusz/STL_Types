cmake_minimum_required(VERSION 3.10)

set(Sources
  ExampleTests.cpp
  IOTests.cpp
  VectorTests.cpp
)

add_executable(ExampleTests ExampleTests.cpp)
add_executable(IOTests IOTests.cpp)
add_executable(VectorTests VectorTests.cpp)

target_link_libraries(ExampleTests PUBLIC
  gtest_main
  Example
)

target_link_libraries(IOTests PUBLIC
  gtest_main
  IO
)

target_link_libraries(VectorTests PUBLIC
  gtest_main
  Vec
)

#add_test(${This} ${This})
add_test(ExampleTests ExampleTests)
add_test(IOTests IOTests)
add_test(VectorTests VectorTests)