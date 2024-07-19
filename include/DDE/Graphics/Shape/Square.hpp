#pragma once

#include <DDE/Graphics/Shape/Shape.hpp>

namespace DDE {

class Square : public DDE::Shape {

private:
  std::vector<unsigned int> _indices;
  unsigned int _elementBufferObject;
  unsigned int _vertexBufferObject;

  void _setUpVertexData(std::vector<float> &vertices);

public:
  Square(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
         DDE::Vertex &vertexThree, DDE::Vertex &vertexFour);
  Square() = delete;
  ~Square() = default;

  void render();
};

} // namespace DDE
