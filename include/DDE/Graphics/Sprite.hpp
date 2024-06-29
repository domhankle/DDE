#pragma once
#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

// TODO: Implement and Document this class
class Sprite {

private:
  unsigned int _vertexArrayObject;
  unsigned int _vertexBufferObject;
  unsigned int _elementBufferObject;
  unsigned int _textureObject;
  DDE::Vertex _position;
  float _width;
  float _height;
  std::vector<float> _vertices;
  const unsigned int _bounds[6] = {0, 1, 2, 1, 2, 3};

  void _initializeGLObjects();
  void _setUpVertexData(DDE::Vertex &origin, float width, float height);

public:
  unsigned int getSpriteObject() const;
  DDE::Vertex getPosition() const;
  float getHeight() const;
  float getWidth() const;
  void render();

  Sprite(DDE::Vertex position, float width, float height);
  Sprite() = delete;
  ~Sprite() = default;
};

} // namespace DDE
