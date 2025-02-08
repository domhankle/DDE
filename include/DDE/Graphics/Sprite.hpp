#pragma once
#include <DDE/Graphics/Texture2D.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
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
  DDE::Vec4 _position;
  DDE::Texture2D _texture;
  // OpenGL vertex data
  std::vector<float> _vertices;
  // Indices for the EBO
  const unsigned int _bounds[6] = {0, 1, 2, 1, 2, 3};

  void _initializeGLObjects();
  void _setUpVertexData(DDE::Vec4 &origin, float width, float height);

public:
  unsigned int getSpriteObject() const;
  DDE::Vec4 getPosition() const;
  float getHeight() const;
  float getWidth() const;
  void render();

  Sprite(DDE::Vec4 position, DDE::Texture2D &texture);
  Sprite() = delete;
  ~Sprite() = default;
};

} // namespace DDE
