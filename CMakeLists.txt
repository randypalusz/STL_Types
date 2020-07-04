cmake_minimum_required(VERSION 3.10)

project(C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# suppress warnings for no symbols if library is STATIC
# some libraries set to SHARED to bypass this
# SET(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
# SET(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
# SET(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
# SET(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")

# add src subdirectory above enable_testing() call
# doesn't make src libraries otherwise...
add_subdirectory(src)

enable_testing()
add_subdirectory(deps/googletest)
add_subdirectory(test)
