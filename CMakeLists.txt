cmake_minimum_required(VERSION 3.31.5)
project(CPPPlayground VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

add_executable(CPPPlayground 
    src/main.cpp
    src/operations.cpp
    src/utils.cpp
    src/errors.cpp
    src/actions.cpp)

set_property(TARGET CPPPlayground PROPERTY CXX_STANDARD 20)