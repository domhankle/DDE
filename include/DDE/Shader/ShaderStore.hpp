#pragma once

#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <unordered_map>

namespace DDE {

class ShaderStore {

private:
  DDE::ShaderStage _currentActiveStage = DDE::ShaderStage::NONE;

  std::unordered_map<DDE::ShaderStage, DDE::ShaderProgram> _pipelineMappings;
  void _cacheShaderPipeline(DDE::ShaderStage stage);

public:
  ShaderStore() = default;
  ~ShaderStore() = default;

  unsigned int loadShaderPipeline(DDE::ShaderStage stage);
  DDE::ShaderStage getActiveShaderStage();
};

} // namespace DDE
