cmake_minimum_required(VERSION 3.31.5)
project(SimpleCalculator VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

file(GLOB SRC_FILES CMAKE_CONFIGURE_DEPENDS src/*.cpp)
add_executable(SimpleCalculator ${SRC_FILES})

set_property(TARGET SimpleCalculator PROPERTY CXX_STANDARD 20)