#pragma once
#include <DDE/Utility/ImageLoader.hpp>
#include <Glad/glad/glad.h>

namespace DDE {

class Texture2D {

private:
  unsigned int _textureObject;
  unsigned char *_imageData;

  void _initializeGLObjects();
  void _configureTexture();

public:
  Texture2D() = delete;
  Texture2D(std::string &filePath);
  ~Texture2D() = default;
};

} // namespace DDE
