#pragma once
#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <Glad/glad/glad.h>

namespace DDE {

// TODO: Implement and Document this class
class Sprite {

private:
  unsigned int _spriteObject;
  unsigned int _vbo;
  DDE::Vertex _position;
  float _width;
  float _height;

public:
  unsigned int getSpriteObject() const;
  DDE::Vertex getPosition() const;

  Sprite();
  ~Sprite() = default;
};

} // namespace DDE
