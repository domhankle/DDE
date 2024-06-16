#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <DDE/Graphics/Sprite.hpp>
#include <exception>
#include <iostream>
#include <vector>

DDE::Sprite::Sprite() {
  glGenVertexArrays(1, &this->_spriteObject);
  glBindVertexArray(this->_spriteObject);

  try {

  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
  }

  glBindVertexArray(0);
}

unsigned int DDE::Sprite::getSpriteObject() const {
  return this->_spriteObject;
}

DDE::Vertex DDE::Sprite::getPosition() const { return this->_position; }
