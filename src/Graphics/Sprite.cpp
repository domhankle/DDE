#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <DDE/Graphics/Sprite.hpp>
#include <exception>
#include <iostream>
#include <vector>

DDE::Sprite::Sprite() {

  try {
    this->_initializeGLObjects();

  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
  }

  glBindVertexArray(0);
}

unsigned int DDE::Sprite::getSpriteObject() const {
  return this->_vertexArrayObject;
}

DDE::Vertex DDE::Sprite::getPosition() const { return this->_position; }

void DDE::Sprite::_initializeGLObjects() {
  glGenVertexArrays(1, &this->_vertexArrayObject);
  glBindVertexArray(this->_vertexArrayObject);
  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
}
