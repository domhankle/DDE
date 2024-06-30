#pragma once
#include <DDE/Utility/Image.hpp>
#include <Glad/glad/glad.h>

namespace DDE {

class Texture2D {

private:
  unsigned int _textureObject;
  DDE::Image _textureImage;

  int _height;
  int _width;

  void _initializeGLObjects();
  void _configureTexture();

public:
  void activate();
  void deactivate();

  int getHeight() const;
  int getWidth() const;

  Texture2D() = delete;
  Texture2D(DDE::Image &image);
  ~Texture2D() = default;
};

} // namespace DDE
