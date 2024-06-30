#include "Glad/glad/glad.h"
#include <DDE/Graphics/Texture2D.hpp>
#include <cstdlib>
#include <iostream>

DDE::Texture2D::Texture2D(DDE::Image &image)
    : _textureImage(image), _height(image.getHeight()),
      _width(image.getWidth()) {

  try {

    this->_initializeGLObjects();
    this->_configureTexture();

  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
    exit(EXIT_FAILURE);
  }
}

void DDE::Texture2D::_initializeGLObjects() {
  glGenTextures(1, &this->_textureObject);
  glBindTexture(GL_TEXTURE_2D, this->_textureObject);
}

void DDE::Texture2D::_configureTexture() {

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_width, this->_height, 0,
               GL_RGBA, GL_UNSIGNED_BYTE, this->_textureImage.getImageData());
  glGenerateMipmap(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, 0);
}

void DDE::Texture2D::activate() {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, this->_textureObject);
}

void DDE::Texture2D::deactivate() { glBindTexture(GL_TEXTURE_2D, 0); }

int DDE::Texture2D::getHeight() const { return this->_height; }
int DDE::Texture2D::getWidth() const { return this->_width; }
