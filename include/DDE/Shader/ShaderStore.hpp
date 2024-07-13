#pragma once

#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <unordered_map>

namespace DDE {

/**
 * @class ShaderStore
 *
 * This class represents where we will store all Shader
 * stages and the currently active shader stage in the app.
 * A shader stage represents the current shader pipeline being
 * processed and tells which objects are being rendered. There
 * should be only one instance of a ShaderStore ever at once,
 * which is the static member variable on the ShaderEngine class.
 *
 * You should only interact with the ShaderStore through the
 * ShaderEngine, there should never be a reason to call
 * it's public member functions directly elsewhere.
 */
class ShaderStore {
 private:
  // The currently active shader stage
  DDE::ShaderStage _currentActiveStage = DDE::ShaderStage::NONE;
  // Used to map ShaderStage enums to OpenGL Shader objects
  std::unordered_map<DDE::ShaderStage, DDE::ShaderProgram> _pipelineMappings;

  void _cacheShaderPipeline(DDE::ShaderStage stage);

 public:
  ShaderStore() = default;
  ~ShaderStore() = default;

  unsigned int loadShaderPipeline(DDE::ShaderStage stage);
  DDE::ShaderStage getActiveShaderStage() const;
};

}  // namespace DDE
