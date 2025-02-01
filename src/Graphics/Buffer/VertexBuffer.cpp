#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Utility/BufferTypes.hpp>
#include <Glad/glad/glad.h>
#include <iostream>

#include <sstream>
#include <vector>

/**
 * The constructor for the VertexBuffer object
 *
 * @param vertices The vertices which will make up this buffer.
 */
DDE::VertexBuffer::VertexBuffer(std::vector<DDE::Vertex> vertices)
    : Buffer(), _vertices{vertices} {
  this->_configureBufferObject();
}

/**
 * This is a wrapper around glBindBuffer. It allows
 * for us to bind the underlying OpenGL buffer that
 * this object abstracts away.
 */
void DDE::VertexBuffer::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, this->_bufferObject);
}

/**
 * This is a wrapper around glBindBuffer. It allows
 * for us to unbind the underlying OpenGL buffer that
 * this object abstracts away.
 */
void DDE::VertexBuffer::unBind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

/**
 * This is a helper function of the class that is
 * utilized to configure the buffer object with data
 * that OpenGL can understand.
 */
void DDE::VertexBuffer::_configureBufferObject() {
  // Retrieve our vertex data in a vector of floats
  std::vector<float> vertexData = this->_getOpenGLData();

  // Bind this buffer object
  this->bind();
  // Tell OpenGL how much space to allocate for this buffer and what it will do.
  glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float),
               vertexData.data(), GL_STATIC_DRAW);
  // Configure vertex attributes
  this->_configureVertexAttributes();
}

/**
 * This is a helper function to convert DDE::Vertex objects
 * into an array of floats that represent vertices OpenGL
 * can understand.
 *
 * @returns An array of floats to represent vertex data in OpenGL
 */
std::vector<float> DDE::VertexBuffer::_getOpenGLData() {

  std::vector<float> toReturn;

  for (const DDE::Vertex &vertex : this->_vertices) {
    toReturn.push_back(vertex.position.x);
    toReturn.push_back(vertex.position.y);
    toReturn.push_back(vertex.position.z);
    toReturn.push_back(vertex.position.w);
    toReturn.push_back(vertex.color.x);
    toReturn.push_back(vertex.color.y);
    toReturn.push_back(vertex.color.z);
    toReturn.push_back(vertex.color.w);
  }

  return toReturn;
}

/**
 * This helper function handles abstracting the process away
 * of describing the structure of our vertex data in the
 * vertex buffer.
 */
void DDE::VertexBuffer::_configureVertexAttributes() {
  // Enable the DDE vertex attribute for POSITION (0)
  glEnableVertexAttribArray(LayoutLocation::POSITION);

  /**
   * Describe the POSITION (0) attribute
   * - 4 components
   * - floats
   * - Not normalized
   * - The start of the next POSITION attribute is 8 floats away
   * - The POSITION attribute is at the start of the buffer
   */
  glVertexAttribPointer(LayoutLocation::POSITION, 4, GL_FLOAT, GL_FALSE,
                        8 * sizeof(float), (void *)0);

  // Enable the DDE vertex attribute for COLOR (1)
  glEnableVertexAttribArray(LayoutLocation::COLOR);

  /**
   * Describe the COLOR (1) attribute
   * - 4 components
   * - floats
   * - Not normalized
   * - The start of the next COLOR attribute is 8 floats away
   * - The COLOR attribute is 4 floats away from the start of the buffer
   */
  glVertexAttribPointer(LayoutLocation::COLOR, 4, GL_FLOAT, GL_FALSE,
                        8 * sizeof(float), (void *)(4 * sizeof(float)));
}

/**
 * This is the function called to print a VertexBuffer object
 * in a human readable format.
 *
 * @returns A string representing the VertexBuffer object
 */
std::string DDE::VertexBuffer::print() const {
  std::stringstream ss;

  for (const DDE::Vertex &vertex : this->_vertices) {
    ss << vertex << std::endl;
  }

  return ss.str();
}
