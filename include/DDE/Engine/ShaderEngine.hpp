#pragma once

#include <DDE/Graphics/Shader/Shader.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Graphics/Shader/ShaderStore.hpp>

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
public:
  // The static single shader store to be used in the lifetime of a DDE app.
  static DDE::ShaderStore shaderStore;

  static void ActivateShaderStage(DDE::ShaderStage stage);
  ShaderEngine() = delete;
};

} // namespace DDE
