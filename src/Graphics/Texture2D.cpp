#include <DDE/Graphics/Texture2D.hpp>
#include <cstdlib>
#include <iostream>

DDE::Texture2D::Texture2D(std::string &filePath) : _imageData(nullptr) {

  try {
    this->_imageData = ImageLoader::loadImage(filePath);

    this->_initializeGLObjects();
    this->_configureTexture();

    ImageLoader::freeImage(this->_imageData);
  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
    exit(EXIT_FAILURE);
  }
}

void DDE::Texture2D::_initializeGLObjects() {
  glGenTextures(1, &this->_textureObject);
  glBindTexture(GL_TEXTURE_2D, this->_textureObject);
}

void DDE::Texture2D::_configureTexture() {}
