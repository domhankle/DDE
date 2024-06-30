#pragma once
#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

/**
 * @class Sprite
 *
 * This class handles abstracting the process
 * of creating a Sprite object connected to a PNG
 * that can be drawn to the screen.
 */
class Sprite {

private:
  // Internal OpenGL VAO
  unsigned int _vertexArrayObject;
  // Internal OpenGL VBO
  unsigned int _vertexBufferObject;
  // Internal OpenGL EBO
  unsigned int _elementBufferObject;
  // Position of the top left of the sprite
  DDE::Vertex _position;
  // Width of the sprite
  float _width;
  // Height of the sprite
  float _height;
  // OpenGL vertex data
  std::vector<float> _vertices;
  // Indices for the EBO
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
