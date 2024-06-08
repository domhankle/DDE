# Specify the project name
project(dom_draw_engine)

# Specify the minimum CMake Version
cmake_minimum_required(VERSION 3.11)

# Specify generation of compile_comands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Store all c/cpp files in SOURCES directory.
set(SOURCES 
    src/dde.cpp
    src/Engine/RenderEngine.cpp
    src/Glad/glad.c
)

# Include GLFW Library
add_subdirectory(deps/glfw)

# Include DDE directories
include_directories(include)

# Add source files to the project executable
add_executable(dom_draw_engine ${SOURCES})

# Link the libraries to the project executable
target_link_libraries(dom_draw_engine glfw)
