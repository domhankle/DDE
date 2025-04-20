#include <DDE/Engine/ShaderEngine.hpp>
#include <glm/fwd.hpp>

// Define the static member variable shaderStore to a default DDE::ShaderStore
DDE::ShaderStore DDE::ShaderEngine::shaderStore;

/**
 * This function is what should be utilized to activate a specific
 * shader stage in other classes. It handles lazily loading the
 * shader pipeline into the shader store.
 *
 * @param stage The shader stage to be activated
 */
void DDE::ShaderEngine::ActivateShaderStage(DDE::ShaderStage stage) {
  if (ShaderEngine::shaderStore.getActiveShaderStage() != stage) {
    glUseProgram(ShaderEngine::shaderStore.loadShaderPipeline(stage));
  }
}

// TODO: Documentation
void DDE::ShaderEngine::UpdateModelMatrix(glm::mat4 matrix) {
  DDE::ShaderProgram activeProgram =
      ShaderEngine::shaderStore.getActiveShaderProgram();
  // TODO: Put 'dde_model_matrix' into an enum
  activeProgram.setMatrix4x4Uniform("dde_model_matrix", matrix);
}
