#pragma once

#include <DDE/Graphics/Shape/Shape.hpp>

namespace DDE {

/**
 * @class Square
 *
 * This class is utilized to abstract the process
 * away of creating a Square that can be drawn to the screen.
 */
class Quad : public DDE::Shape {

private:
  // Utilized in the EBO for drawing the Square
  std::vector<unsigned int> _indices;
  // The OpenGL element buffer object
  unsigned int _elementBufferObject;
  // The OpenGL vertex buffer object
  unsigned int _vertexBufferObject;

  void _setUpVertexData(std::vector<float> &vertices);
  void _setUpElementsBuffer(std::vector<unsigned int> &indices);

  std::vector<float> _reorganizeVertices(std::vector<DDE::Vertex> &vertices);
  DDE::Vertex _getCentroidVertex(std::vector<DDE::Vertex> &vertices);

public:
  Quad(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo, DDE::Vertex &vertexThree,
       DDE::Vertex &vertexFour);
  Quad() = delete;
  ~Quad() = default;

  void render();
};

} // namespace DDE
