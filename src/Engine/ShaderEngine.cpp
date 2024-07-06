#include <DDE/Engine/ShaderEngine.hpp>

DDE::ShaderStore DDE::ShaderEngine::shaderStore;

void DDE::ShaderEngine::ActivateShaderStage(DDE::ShaderStage stage) {

  if (ShaderEngine::shaderStore.getActiveShaderStage() != stage) {
    glUseProgram(ShaderEngine::shaderStore.loadShaderPipeline(stage));
  }
}
