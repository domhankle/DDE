#pragma once
#include <DDE/Utility/Image.hpp>
#include <Glad/glad/glad.h>

namespace DDE {

/**
 * @class Texture2D
 *
 * This class handles abstracting away a 2D texture
 * that can be generated in OpenGL.
 */
class Texture2D {

private:
  // The OpenGL texture object
  unsigned int _textureObject;
  // The image associated with this texture
  DDE::Image _textureImage;

  // The height of the texture
  int _height;
  // The width of the texture
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
