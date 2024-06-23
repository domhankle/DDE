#pragma once

#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

class Triangle {

private:
  std::vector<float> _vertices;
  unsigned int _vertexBufferObject;
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
