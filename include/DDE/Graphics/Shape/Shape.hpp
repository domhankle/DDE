#pragma once

#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Drawable.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

/**
 * @class Shape
 *
 * This is the abstract base class for all of the primitive
 * shapes that can be rendered in the DDE library.
 */
class Shape : public DDE::Drawable {

protected:
  // The OpenGL VAO object associated with this shape
  unsigned int _vertexArrayObject;

  void _initializeGLObjects();
  virtual void _setUpVertexData(DDE::VertexBuffer &vbo) = 0;
  Shape(DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});

public:
  virtual void render() = 0;
  ~Shape() = default;
};

} // namespace DDE
