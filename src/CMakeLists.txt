
# Include our other top level modules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Engine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Glad)

# Append dde.cpp to SOURCES variable
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dde.cpp
    ${ENGINE_SOURCES}
    ${GLAD_SOURCES}
    PARENT_SCOPE)
