file(GLOB SRC_FILES CMAKE_CONFIGURE_DEPENDS src/*.cpp)
add_executable(SimpleCalculator ${SRC_FILES})

set_property(TARGET SimpleCalculator PROPERTY CXX_STANDARD 20)