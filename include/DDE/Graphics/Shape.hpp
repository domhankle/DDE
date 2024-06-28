#pragma once

#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

/**
 * @class Triangle
 *
 * This class is used to handle abstracting
 * the drawing of a Triangle Primitive in
 * OpenGL.
 */
class Triangle {

private:
  // The vertices associated with this Triangle
  std::vector<float> _vertices;

  // The OpenGL VBO for this Triangle
  unsigned int _vertexBufferObject;

  // The OpenGL VAO for this Triangle
  unsigned int _vertexArrayObject;

  void _initializeGLObjects();
  void _setUpVertexData(std::vector<float> &vertices);

public:
  Triangle(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
           DDE::Vertex &vertexThree);
  Triangle() = delete;
  ~Triangle() = default;

  void render();
};

} // namespace DDE
