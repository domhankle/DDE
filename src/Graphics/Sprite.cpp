#include "DDE/Graphics/Vertex/Vertex.hpp"
#include "Glad/glad/glad.h"
#include <DDE/Graphics/Sprite.hpp>
#include <exception>
#include <iostream>
#include <vector>

// TODO: Add documentation

DDE::Sprite::Sprite(DDE::Vertex position, float width, float height)
    : _position{position.x, position.y, position.z, position.w}, _width(width),
      _height(height) {

  try {
    this->_initializeGLObjects();
    this->_setUpVertexData(this->_position, this->_width, this->_height);
  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
  }

  glBindVertexArray(0);
}

void DDE::Sprite::_initializeGLObjects() {
  glGenVertexArrays(1, &this->_vertexArrayObject);
  glBindVertexArray(this->_vertexArrayObject);
  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
  glGenBuffers(1, &this->_elementBufferObject);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_elementBufferObject);
}

void DDE::Sprite::_setUpVertexData(DDE::Vertex &origin, float width,
                                   float height) {
  this->_vertices = {origin.x,         origin.y,          origin.z,
                     origin.x + width, origin.y,          origin.z,
                     origin.x,         origin.y - height, origin.z,
                     origin.x + width, origin.y - height, origin.z};

  glBufferData(GL_ARRAY_BUFFER, this->_vertices.size() * sizeof(float),
               this->_vertices.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->_bounds), this->_bounds,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DDE::Sprite::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

unsigned int DDE::Sprite::getSpriteObject() const {
  return this->_vertexArrayObject;
}

DDE::Vertex DDE::Sprite::getPosition() const { return this->_position; }

float DDE::Sprite::getHeight() const { return this->_height; }

float DDE::Sprite::getWidth() const { return this->_width; }
