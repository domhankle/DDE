#include "DDE/Graphics/Vertex/Vertex.hpp"
#include "Glad/glad/glad.h"
#include <DDE/Graphics/Sprite.hpp>
#include <exception>
#include <iostream>
#include <vector>

/**
 * This is the only constructor available for Sprite objects
 *
 * @param position The top left of the sprite will be located at
 * this position.
 * @param width The width of the sprite
 * @param height The height of the sprite
 */
DDE::Sprite::Sprite(DDE::Vertex position, DDE::Texture2D &texture)
    : _position{position.x, position.y, position.z, position.w},
      _texture{texture} {

  try {
    this->_initializeGLObjects();
    this->_setUpVertexData(this->_position, this->_texture.getWidth(),
                           this->_texture.getHeight());
  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
    exit(EXIT_FAILURE);
  }

  glBindVertexArray(0);
}

/**
 * This function handles initializing the OpenGL
 * objects that are used internally for the Sprite
 * class.
 */
void DDE::Sprite::_initializeGLObjects() {
  glGenVertexArrays(1, &this->_vertexArrayObject);
  glBindVertexArray(this->_vertexArrayObject);
  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
  glGenBuffers(1, &this->_elementBufferObject);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_elementBufferObject);
}

/**
 * This function actually handles configuring vertex data
 * for the internal OpenGL objects used by the Sprite class
 *
 * @param origin The top left location for the sprite
 * @param width The width of this sprite
 * @param height The height of this sprite
 */
void DDE::Sprite::_setUpVertexData(DDE::Vertex &origin, float width,
                                   float height) {
  this->_vertices = {origin.x,         origin.y,          0.0f, 1.0f,
                     origin.x + width, origin.y,          1.0f, 1.0f,
                     origin.x,         origin.y - height, 0.0f, 0.0f,
                     origin.x + width, origin.y - height, 1.0f, 0.0f};

  glBufferData(GL_ARRAY_BUFFER, this->_vertices.size() * sizeof(float),
               this->_vertices.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->_bounds), this->_bounds,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                        (void *)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * This function is called when it is time to actually
 * render the sprite object.
 */
void DDE::Sprite::render() {
  this->_texture.activate();
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  this->_texture.deactivate();
}

/**
 * This function is used to obtain the internal OpenGL
 * VAO object for this sprite object.
 *
 * @returns VAO
 */
unsigned int DDE::Sprite::getSpriteObject() const {
  return this->_vertexArrayObject;
}

/**
 * This function is used to get the position of the
 * top left of the sprite object.
 *
 * @returns DDE::Vertex
 */
DDE::Vertex DDE::Sprite::getPosition() const { return this->_position; }
