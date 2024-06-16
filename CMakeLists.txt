# Specify the project name
project(dom_draw_engine)

# Specify the minimum CMake Version
cmake_minimum_required(VERSION 3.11)

# Specify minimum C++ Compiler to Use
set(CMAKE_CXX_STANDARD 20)

# Specify generation of compile_comands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include GLFW Library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw)

# Include src directory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Include DDE directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add source files to the project executable
add_executable(dom_draw_engine ${SOURCES})

# Link the libraries to the project executable
target_link_libraries(dom_draw_engine glfw)
