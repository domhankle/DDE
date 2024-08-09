# Append the src files to SOURCES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Vertex)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Shape)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Shader)

set(GRAPHICS_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/Texture2D.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Drawable.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Pencil.cpp
  ${VERTEX_SOURCES}
  ${SHAPE_SOURCES}
  ${SHADER_SOURCES}
  PARENT_SCOPE)
