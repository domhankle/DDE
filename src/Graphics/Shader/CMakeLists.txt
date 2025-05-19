add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Frustum)

# Append the src files to SOURCES
set(SHADER_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/ShaderProgram.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/ShaderStore.cpp
  ${FRUSTUM_SOURCES}
  PARENT_SCOPE)

