# Include our DrawConfig directory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/DrawConfig)

# Append the src files to SOURCES
set(UTILITY_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp
  ${DRAW_CONFIG_SOURCES}
  PARENT_SCOPE)
