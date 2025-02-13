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
  // The VertexBuffer object associated with this Triangle
  DDE::VertexBuffer _vertexBuffer;

  // The height of the triangle
  float _height;

  // The base length of the triangle
  float _base;

  void _setUpVertexData(DDE::VertexBuffer &vbo) override;

public:
  Triangle(float base, float height,
           DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});
  Triangle() = delete;
  ~Triangle() = default;

  void render() override;
};
} // namespace DDE
