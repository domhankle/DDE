
# Include our other top level modules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Engine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Shader)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Graphics)

# Append dde.cpp to SOURCES variable
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dde.cpp
    ${ENGINE_SOURCES}
    ${GLAD_SOURCES}
    ${SHADER_SOURCES}
    ${GRAPHICS_SOURCES}
    PARENT_SCOPE)
