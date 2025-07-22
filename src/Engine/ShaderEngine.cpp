#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Shader/Camera/Camera.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <glm/fwd.hpp>

// Define the static member variable shaderStore to a default DDE::ShaderStore
DDE::ShaderStore DDE::ShaderEngine::_shaderStore;

/**
 * This function is what should be utilized to activate a specific
 * shader stage in other classes. It handles lazily loading the
 * shader pipeline into the shader store.
 *
 * @param stage The shader stage to be activated
 */
void DDE::ShaderEngine::ActivateShaderStage(DDE::ShaderStage stage) {
  if (ShaderEngine::_shaderStore.getActiveShaderStage() != stage) {
    glUseProgram(ShaderEngine::_shaderStore.loadShaderPipeline(stage));
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
      ShaderEngine::_shaderStore.getActiveShaderProgram();

  // Set our 'dde_model_matrix' uniform variable to the matrix passed
  activeProgram.setMatrix4x4Uniform(DDE::ShaderUniform::MODEL_MATRIX, matrix);
}

/**
 * This function is used to update the projection matrix on
 * the currently active shader.
 *
 * @param matrix The matrix we are setting the projection matrix uniform to
 */
void DDE::ShaderEngine::UpdateProjectionMatrix(glm::mat4 matrix) {
  // Get the active ShaderProgram object from our singleton ShaderStore
  DDE::ShaderProgram activeProgram =
      ShaderEngine::_shaderStore.getActiveShaderProgram();

  // Set our 'dde_projection_matrix' uniform variable to the matrix passed
  activeProgram.setMatrix4x4Uniform(DDE::ShaderUniform::PROJECTION_MATRIX,
                                    matrix);
}

/**
 * This function is used to update the view matrix on
 * the currently active shader.
 *
 * @param matrix The matrix we are setting the view matrix uniform to
 */
void DDE::ShaderEngine::UpdateViewMatrix(glm::mat4 matrix) {
  // Get the active ShaderProgram object from our singleton ShaderStore
  DDE::ShaderProgram activeProgram =
      ShaderEngine::_shaderStore.getActiveShaderProgram();

  // Set our 'dde_view_matrix' uniform variable to the matrix passed
  activeProgram.setMatrix4x4Uniform(DDE::ShaderUniform::VIEW_MATRIX, matrix);
}
