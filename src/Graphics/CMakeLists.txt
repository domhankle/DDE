# Append the src files to SOURCES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Vertex)

set(GRAPHICS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp 
    ${VERTEX_SOURCES}
    PARENT_SCOPE)
