#pragma once

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
class Shape {

protected:
  // The vertices for the shape to draw
  std::vector<float> _vertices;

  // The OpenGL VBO object associated with this shape
  unsigned int _vertexBufferObject;

  // The OpenGL VAO object associated with this shape
  unsigned int _vertexArrayObject;
  void _initializeGLObjects();
  virtual void _setUpVertexData(std::vector<float> &vertices) = 0;

public:
  virtual void render() = 0;
  Shape() = delete;
  Shape(std::initializer_list<float> vertices);
};
} // namespace DDE
