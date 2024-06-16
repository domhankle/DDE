#include <DDE/Graphics/Sprite.hpp>
#include <exception>
#include <iostream>

DDE::Sprite::Sprite() {
  glGenVertexArrays(1, &this->_spriteObject);
  glBindVertexArray(this->_spriteObject);

  try {

  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
  }

  glBindVertexArray(0);
}
