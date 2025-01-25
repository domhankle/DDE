#pragma once

#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <ostream>
#include <vector>

namespace DDE {

// TODO: Documentation
class VertexBuffer : public Buffer {

private:
  // TODO: Documentation
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

// TODO: Documentation
inline std::ostream &operator<<(std::ostream &os,
                                const VertexBuffer &vertexBuffer) {
  os << vertexBuffer.print();
  return os;
}

} // namespace DDE
