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
DDE::Sprite::Sprite(DDE::Vertex position, float width, float height)
    : _position{position.x, position.y, position.z, position.w}, _width(width),
      _height(height) {

  try {
    this->_initializeGLObjects();
    this->_setUpVertexData(this->_position, this->_width, this->_height);
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
  this->_vertices = {origin.x,         origin.y,          origin.z,
                     origin.x + width, origin.y,          origin.z,
                     origin.x,         origin.y - height, origin.z,
                     origin.x + width, origin.y - height, origin.z};

  glBufferData(GL_ARRAY_BUFFER, this->_vertices.size() * sizeof(float),
               this->_vertices.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->_bounds), this->_bounds,
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * This function is called when it is time to actually
 * render the sprite object.
 */
void DDE::Sprite::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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

/**
 * This function is used to get the height of the
 * sprite object.
 *
 * @returns float
 */
float DDE::Sprite::getHeight() const { return this->_height; }

/**
 * This function is used to get the width of the
 * sprite object.
 *
 * @returns float
 */
float DDE::Sprite::getWidth() const { return this->_width; }
