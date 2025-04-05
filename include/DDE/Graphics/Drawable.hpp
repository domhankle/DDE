#pragma once
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Vertex/Vec4.hpp>
#include <DDE/Utility/ShaderTypes.hpp>

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
  // The color of the drawable object.
  DDE::Vec4 _color;

  virtual void _initializeGLObjects() = 0;
  virtual void _setUpVertexData(DDE::VertexBuffer &vbo) = 0;

  Drawable() = delete;
  Drawable(DDE::ShaderStage shaderPipeline,
           DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});

public:
  DDE::ShaderStage getShaderPipeline() const;
  ~Drawable() = default;
  virtual void render() = 0;
};

} // namespace DDE
