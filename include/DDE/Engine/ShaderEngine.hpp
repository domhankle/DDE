#pragma once

#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>
#include <DDE/Shader/ShaderStore.hpp>

namespace DDE {

class ShaderEngine {
public:
  static void ActivateShaderStage(DDE::ShaderStage stage);
  static DDE::ShaderStore shaderStore;
  ShaderEngine() = delete;
};

} // namespace DDE
