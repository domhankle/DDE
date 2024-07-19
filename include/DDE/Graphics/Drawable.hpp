#pragma once
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <vector>

namespace DDE {

/**
 * @class Drawable
 *
 * This class is an abstract base class which all objects
 * that can be rendered in a DDE application will inherit
 * from.
 */
class Drawable {

protected:
  // The shader pipeline that this drawable will utilize.
  DDE::ShaderStage _shaderPipelineID;

  virtual void _initializeGLObjects() = 0;
  virtual void _setUpVertexData(std::vector<float> &vertices) = 0;

  Drawable() = delete;
  Drawable(DDE::ShaderStage shaderPipeline);

public:
  DDE::ShaderStage getShaderPipeline() const;
  ~Drawable() = default;
  virtual void render() = 0;
};

} // namespace DDE
