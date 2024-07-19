#include "Glad/glad/glad.h"
#include <DDE/Graphics/Shape/Square.hpp>

DDE::Square::Square(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
                    DDE::Vertex &vertexThree, DDE::Vertex &vertexFour)
    : Shape({vertexOne.x, vertexOne.y, vertexOne.z, vertexTwo.x, vertexTwo.y,
             vertexTwo.z, vertexThree.x, vertexThree.y, vertexThree.z,
             vertexFour.x, vertexFour.y, vertexFour.z}),
      _indices{0, 1, 2, 1, 2, 3} {

  this->_setUpVertexData(this->_vertices);

  glBindVertexArray(0);
}

void DDE::Square::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void DDE::Square::_setUpVertexData(std::vector<float> &vertices) {

  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glGenBuffers(1, &this->_elementBufferObject);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_elementBufferObject);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               this->_indices.size() * sizeof(unsigned int),
               this->_indices.data(), GL_STATIC_DRAW);
}
