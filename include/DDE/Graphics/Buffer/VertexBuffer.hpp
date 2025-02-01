#pragma once

#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <ostream>
#include <vector>

namespace DDE {

/**
 * @class VertexBuffer
 *
 * This class abstracts the process of creating
 * a vertex buffer in OpenGL. It handles creating
 * the buffer object, populating it with specified
 * vertices, and can be binded/unbinded to the OpenGL
 * context.
 */
class VertexBuffer : public Buffer {

private:
  // The list of vertices to store in this buffer
  std::vector<DDE::Vertex> _vertices;

  void _configureBufferObject() override;
  void _configureVertexAttributes() override;
  std::vector<float> _getOpenGLData() override;

public:
  VertexBuffer() = default;
  VertexBuffer(std::vector<DDE::Vertex> vertices);
  void unBind() override;
  void bind() override;

  std::string print() const;
};

/**
 * This function allows us to write VertexBuffer objects
 * to some stream in a human readable format.
 *
 * @param os The stream we are writing to.
 * @param VertexBuffer The vertex buffer object we are writing.
 *
 * @returns The resulting stream with a vertex buffer object written to it.
 */
inline std::ostream &operator<<(std::ostream &os,
                                const VertexBuffer &vertexBuffer) {
  os << vertexBuffer.print();
  return os;
}

} // namespace DDE
