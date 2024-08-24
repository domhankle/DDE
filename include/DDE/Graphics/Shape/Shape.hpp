#pragma once

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
  // The vertices for the shape to draw
  std::vector<float> _vertices;
  // The OpenGL VAO object associated with this shape
  unsigned int _vertexArrayObject;

  void _initializeGLObjects();
  virtual void _setUpVertexData(std::vector<float> &vertices) = 0;
  Shape(std::initializer_list<float> vertices,
        DDE::Vertex color = DDE::Vertex{1.0f, 1.0f, 1.0f, 1.0f});
  Shape();

public:
  virtual void render() = 0;
  ~Shape() = default;
};

} // namespace DDE
