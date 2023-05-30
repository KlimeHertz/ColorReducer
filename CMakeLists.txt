cmake_minimum_required(VERSION 3.16)
project(ColorReducer)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "C:/boost_1_81_0")
set(BOOSTROOT "C:/boost_1_81_0")
find_package(Boost 1.81.0)
set(Boost_INCLUDE_DIR C:/boost_1_81_0/)
set(Boost_LIBRARY_DIR C:/boost_1_81_0/stage/lib)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(ColorReducer main.cpp Color.cpp Color.h FileManager.cpp FileManager.h ColorReductor.cpp ColorReductor.h)