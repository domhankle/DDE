#pragma once
#include "DDE/Graphics/Buffer/VertexBuffer.hpp"
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Shape/Shape.hpp>

namespace DDE {

/**
 * @class Triangle
 *
 * This class is used to handle abstracting
 * the drawing of a Triangle Primitive in
 * OpenGL.
 */
class Triangle : public DDE::Shape {

private:
  // TODO: Documentation
  DDE::VertexBuffer _vertexBuffer;
  // TODO: Documentation
  float _height;
  // TODO: Documentation
  float _base;

  void _setUpVertexData(DDE::VertexBuffer &vbo) override;

public:
  Triangle(float base, float height);
  Triangle() = delete;
  ~Triangle() = default;

  void render() override;
};
} // namespace DDE
