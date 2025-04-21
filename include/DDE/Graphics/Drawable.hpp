#pragma once
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Vertex/Vec4.hpp>
#include <DDE/Utility/ShaderTypes.hpp>
#include <glm/glm.hpp>

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
  // The model matrix for this drawable object.
  glm::mat4 _modelMatrix;

  // TODO: Documentation
  DDE::Vec4 _position;

  // TODO: Documentation
  DDE::Vec4 _size;

  virtual void _initializeGLObjects() = 0;
  virtual void _setUpVertexData(DDE::VertexBuffer &vbo) = 0;

  Drawable() = delete;
  Drawable(DDE::ShaderStage shaderPipeline,
           DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});

public:
  glm::mat4 getModelMatrix() const;
  DDE::ShaderStage getShaderPipeline() const;
  DDE::Vec4 getPosition() const;
  DDE::Vec4 getSize() const;

  void translate(glm::vec3 directionVector);
  void rotate(float degrees, glm::vec3 rotationVector);
  void scale(glm::vec3 scaleVector);

  ~Drawable() = default;
  virtual void render() = 0;
};

} // namespace DDE
