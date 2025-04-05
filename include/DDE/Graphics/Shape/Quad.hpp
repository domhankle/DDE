#pragma once

#include "DDE/Graphics/Buffer/VertexBuffer.hpp"
#include <DDE/Graphics/Shape/Shape.hpp>

namespace DDE {

/**
 * @class Quad
 *
 * This class is utilized to abstract the process away of
 * creating an arbitrary Quad that can be drawn to the screen.
 */
class Quad : public DDE::Shape {

private:
  // The OpenGL vertex buffer object
  DDE::VertexBuffer _vertexBuffer;
  // The width of the quad
  float _width;
  // The height of the quad
  float _height;

  void _setUpVertexData(DDE::VertexBuffer &vbo) override;

public:
  Quad(float width, float height,
       DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});
  Quad() = delete;
  ~Quad() = default;

  void render() override;
};

} // namespace DDE
