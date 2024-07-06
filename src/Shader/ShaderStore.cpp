#include "DDE/Utility/ShaderTypes.hpp"
#include <DDE/Shader/ShaderStore.hpp>
#include <Glad/glad/glad.h>
#include <iostream>
#include <stdexcept>

unsigned int DDE::ShaderStore::loadShaderPipeline(DDE::ShaderStage stage) {

  if (this->_pipelineMappings.find(stage) == this->_pipelineMappings.end()) {
    try {
      this->_cacheShaderPipeline(stage);
    } catch (std::exception &exception) {
      std::cerr << "Failed to activate a Shader Stage!\n " << exception.what();
      exit(EXIT_FAILURE);
    }
  }

  this->_currentActiveStage = stage;
  return this->_pipelineMappings.at(stage).getProgramObject();
}

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

DDE::ShaderStage DDE::ShaderStore::getActiveShaderStage() {
  return this->_currentActiveStage;
}
