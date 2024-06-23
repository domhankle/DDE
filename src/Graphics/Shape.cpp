#include "Glad/glad/glad.h"
#include <DDE/Graphics/Shape.hpp>
#include <iostream>

DDE::Triangle::Triangle(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
                        DDE::Vertex &vertexThree)
    : _vertices{vertexOne.x,   vertexOne.y,   vertexOne.z,
                vertexTwo.x,   vertexTwo.y,   vertexTwo.z,
                vertexThree.x, vertexThree.y, vertexThree.z} {

  this->_initializeGLObjects();
  this->_setUpVertexData(this->_vertices);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void DDE::Triangle::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DDE::Triangle::_initializeGLObjects() {

  glGenVertexArrays(1, &this->_vertexArrayObject);
  glBindVertexArray(this->_vertexArrayObject);

  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
}

void DDE::Triangle::_setUpVertexData(std::vector<float> &vertices) {

  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
}
