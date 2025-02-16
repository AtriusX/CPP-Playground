cmake_minimum_required(VERSION 3.31.5)
project(CPPPlayground VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

file(GLOB SRC_FILES CMAKE_CONFIGURE_DEPENDS src/*.cpp)
add_executable(CPPPlayground ${SRC_FILES})

set_property(TARGET CPPPlayground PROPERTY CXX_STANDARD 20)