#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <iostream>
#include <vector>

/**
 * Constructor for a Square shape based on width/height. The
 * origin of this shape will be located in the center of the
 * screen.
 *
 * @param width The horizontal width of the shape
 * @param height The vertical height of the shape
 */
DDE::Quad::Quad(float width, float height) : _width(width), _height(height) {

  this->_setUpVertexData(this->_vertexBuffer);
}

// TODO: Documentation
void DDE::Quad::_setUpVertexData(DDE::VertexBuffer &vbo) {
  std::vector<DDE::Vertex> vertices;

  std::vector<DDE::Vec4> positions;
  positions.push_back(DDE::Vec4{-this->_width / 2, -this->_height / 2});
  positions.push_back(DDE::Vec4{this->_width / 2, -this->_height / 2});
  positions.push_back(DDE::Vec4{this->_width / 2, this->_height / 2});
  positions.push_back(DDE::Vec4{this->_width / 2, this->_height / 2});
  positions.push_back(DDE::Vec4{-this->_width / 2, this->_height / 2});
  positions.push_back(DDE::Vec4{-this->_width / 2, -this->_height / 2});

  for (DDE::Vec4 &position : positions) {
    vertices.push_back(position);
  }

  vbo = DDE::VertexBuffer{vertices};

  glBindVertexArray(0);
}

/**
 * This is the required render function that describes
 * how a Square object will be drawn to the screen.
 */
void DDE::Quad::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}
