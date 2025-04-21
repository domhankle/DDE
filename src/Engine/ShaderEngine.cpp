#include "DDE/Utility/ShaderTypes.hpp"
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

/**
 * This function is used by the ShaderEngine to update the
 * active model matrix in the active DDE Shader to ensure that
 * the object that is about to be drawn is accurate to what it's
 * model matrix is.
 *
 * @param matrix The matrix to update the 'dde_model_matrix' uniform
 *               variable to.
 */
void DDE::ShaderEngine::UpdateModelMatrix(glm::mat4 matrix) {
  // Get the active ShaderProgram object from our singleton ShaderStore
  DDE::ShaderProgram activeProgram =
      ShaderEngine::shaderStore.getActiveShaderProgram();

  // Set our 'dde_model_matrix' uniform variable to the matrix passed
  activeProgram.setMatrix4x4Uniform(DDE::ShaderUniform::MODEL_MATRIX, matrix);
}
