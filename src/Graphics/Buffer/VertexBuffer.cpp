
#include "DDE/Utility/BufferTypes.hpp"
#include "Glad/glad/glad.h"
#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <vector>

// TODO: Documentation
DDE::VertexBuffer::VertexBuffer(std::vector<DDE::Vertex> positions,
                                DDE::Vertex color)
    : Buffer(), _positionVertices{positions}, _color{color} {
  this->_configureBufferObject();
}

// TODO: Documentation
void DDE::VertexBuffer::bind() {
  glBindBuffer(GL_ARRAY_BUFFER, this->_bufferObject);
}

// TODO: Documentation
void DDE::VertexBuffer::unBind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

// TODO: Documentation
void DDE::VertexBuffer::_configureBufferObject() {
  std::vector<float> vertexData = this->_transformToOpenGLData();
  this->bind();
  glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float),
               vertexData.data(), GL_STATIC_DRAW);
}

// TODO: Documentation
std::vector<float> DDE::VertexBuffer::_transformToOpenGLData() {

  std::vector<float> toReturn;
  for (const DDE::Vertex &vertex : this->_positionVertices) {
    toReturn.push_back(vertex.x);
    toReturn.push_back(vertex.y);
    toReturn.push_back(vertex.z);
    toReturn.push_back(vertex.w);
    toReturn.push_back(this->_color.x);
    toReturn.push_back(this->_color.y);
    toReturn.push_back(this->_color.z);
    toReturn.push_back(this->_color.w);
  }

  return toReturn;
}

// TODO: Documentation
void DDE::VertexBuffer::_configureVertexAttributes() {
  glEnableVertexAttribArray(LayoutLocation::POSITION);
  glVertexAttribPointer(LayoutLocation::POSITION, 4, GL_FLOAT, GL_FALSE,
                        8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(LayoutLocation::COLOR);
  glVertexAttribPointer(LayoutLocation::COLOR, 4, GL_FLOAT, GL_FALSE,
                        8 * sizeof(float), (void *)4);
}
