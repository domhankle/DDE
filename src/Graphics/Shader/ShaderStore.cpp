#include <Glad/glad/glad.h>

#include <DDE/Graphics/Shader/ShaderStore.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <iostream>
#include <stdexcept>

/**
 * Handles retrieving the associated OpenGL Program object for a specified
 * ShaderStage. The OpenGL Program objects are lazily generated through this
 * function, if one is loaded yet we will call _cacheShaderPipeline to generate
 * it and then load it.
 *
 * @param stage The specific ShaderStage we want to get the OpenGL Program
 * object for.
 *
 * @returns The associated OpenGL program object connected to the ShaderStage
 *          specified.
 */
unsigned int DDE::ShaderStore::loadShaderPipeline(DDE::ShaderStage stage) {
  // First see if the Program object doesn't exist in the map.
  if (this->_pipelineMappings.find(stage) == this->_pipelineMappings.end()) {
    // If it doesn't, create the associated Shader Program pipeline.
    try {
      this->_cacheShaderPipeline(stage);
    } catch (std::exception &exception) {
      std::cerr << "Failed to activate a Shader Stage!\n " << exception.what();
      exit(EXIT_FAILURE);
    }
  }

  // Configure the current active stage property.
  this->_currentActiveStage = stage;

  return this->_pipelineMappings.at(stage).getProgramObject();
}

/**
 * This function handles generating a ShaderProgram object that
 * will be stored in the _pipelineMappings property.
 *
 * @param stage The associated ShaderStage to generate a pipeline for.
 */
void DDE::ShaderStore::_cacheShaderPipeline(DDE::ShaderStage stage) {
  switch (stage) {
  case DDE::ShaderStage::PRIMITIVE:
    this->_pipelineMappings.insert(
        {stage,
         DDE::ShaderProgram(
             {DDE::Shader("../glsl/primitive/primitive.vert", GL_VERTEX_SHADER),
              DDE::Shader("../glsl/primitive/primitive.frag",
                          GL_FRAGMENT_SHADER)})});
    break;
  case DDE::ShaderStage::SCENE:
    throw std::runtime_error("Not Implemented!\n");
    break;
  case DDE::ShaderStage::OBJECT:
    throw std::runtime_error("Not Implemented!\n");
    break;
  default:
    throw std::runtime_error(
        "Invalid Shader Stage was Provided to the Shader Engine!\n");
  }
}

/**
 * Retrieve the current ShaderStage active.
 *
 * @returns The currently active ShaderStage that will be used for rendering.
 */
DDE::ShaderStage DDE::ShaderStore::getActiveShaderStage() const {
  return this->_currentActiveStage;
}
