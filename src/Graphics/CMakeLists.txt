# Append the src files to SOURCES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Vertex)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Shape)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Shader)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Buffer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Pencil)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Scene)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Artist)

set(GRAPHICS_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/Texture2D.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Drawable.cpp
  ${VERTEX_SOURCES}
  ${SHAPE_SOURCES}
  ${SHADER_SOURCES}
  ${BUFFER_SOURCES}
  ${PENCIL_SOURCES}
  ${SCENE_SOURCES}
  ${ARTIST_SOURCES}
  PARENT_SCOPE)
