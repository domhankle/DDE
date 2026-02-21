#pragma once
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
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
  glm::vec4 _color;
  // The model matrix for this drawable object.
  glm::mat4 _modelMatrix;

  // The current position of this drawable object.
  glm::vec3 _position;

  // The current scale of this drawable object on each axis.
  glm::vec3 _scale;

  virtual void _initializeGLObjects() = 0;
  virtual void _setUpVertexData(DDE::VertexBuffer &vbo) = 0;

  Drawable() = delete;
  Drawable(DDE::ShaderStage shaderPipeline,
           glm::vec4 color = glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});

public:
  glm::mat4 getModelMatrix() const;
  DDE::ShaderStage getShaderPipeline() const;
  glm::vec3 getPosition() const;
  glm::vec3 getScale() const;

  void translate(glm::vec3 directionVector);
  void rotate(float degrees, glm::vec3 rotationVector);
  void scale(glm::vec3 scaleVector);

  ~Drawable() = default;
  virtual void render() = 0;
};

} // namespace DDE
