#pragma once
#include <DDE/Graphics/Shader/Camera/Camera.hpp>
#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <DDE/Graphics/Shader/Shader.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Graphics/Shader/ShaderStore.hpp>
#include <glm/fwd.hpp>

namespace DDE {

/**
 * @class ShaderEngine
 *
 * This is a singleton class that will be used to handle shader
 * staging for this library. We want to ensure that first
 * primitive objects are rendered, then sprites, then landscapes,
 * etc.
 */
class ShaderEngine {
private:
  // The static single shader store to be used in the lifetime of a DDE app.
  static DDE::ShaderStore _shaderStore;

public:
  static void ActivateShaderStage(DDE::ShaderStage stage);
  static void UpdateModelMatrix(glm::mat4 matrix);
  static void UpdateProjectionMatrix(glm::mat4 matrix);

  ShaderEngine() = delete;
};

} // namespace DDE
