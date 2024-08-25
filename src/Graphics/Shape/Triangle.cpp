#include "DDE/Graphics/Buffer/VertexBuffer.hpp"
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>

/**
 * Triangle base/height constructor
 *
 * @param base The length of the base of the triangle
 * @param height The height of the triangle
 */
DDE::Triangle::Triangle(float base, float height)
    : _base(base), _height(height) {
  this->_setUpVertexData(this->_vertexBuffer);
}

// TODO: Documentation
void DDE::Triangle::_setUpVertexData(DDE::VertexBuffer &vbo) {
  std::vector<DDE::Vertex> positions;
  positions.push_back(DDE::Vertex{-this->_base / 2, -this->_height / 2});
  positions.push_back(DDE::Vertex{this->_base / 2, -this->_height / 2});
  positions.push_back(DDE::Vertex{0.0f, this->_height / 2});

  vbo = DDE::VertexBuffer{positions};
  glBindVertexArray(0);
}

/**
 * This function is used to actually render
 * the triangle object to the screen.
 */
void DDE::Triangle::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
