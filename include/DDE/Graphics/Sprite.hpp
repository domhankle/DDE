#pragma once
#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <Glad/glad/glad.h>

namespace DDE {

// TODO: Implement and Document this class
class Sprite {

private:
  unsigned int _vertexArrayObject;
  unsigned int _vertexBufferObject;
  DDE::Vertex _position;
  float _width;
  float _height;

  void _initializeGLObjects();

public:
  unsigned int getSpriteObject() const;
  DDE::Vertex getPosition() const;

  Sprite();
  ~Sprite() = default;
};

} // namespace DDE
