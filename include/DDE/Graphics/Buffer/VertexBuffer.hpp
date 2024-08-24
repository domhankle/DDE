#pragma once

#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <vector>

namespace DDE {

// TODO: Documentation
class VertexBuffer : public Buffer {

private:
  // TODO: Documentation
  std::vector<DDE::Vertex> _positionVertices;
  // TODO: Documentation
  DDE::Vertex _color;

  void _configureBufferObject() override;
  void _configureVertexAttributes() override;
  std::vector<float> _transformToOpenGLData() override;

public:
  VertexBuffer() = delete;
  VertexBuffer(std::vector<DDE::Vertex> positions,
               DDE::Vertex color = DDE::Vertex{1.0f, 1.0f, 1.0f, 1.0f});
  void unBind() override;
  void bind() override;
};

} // namespace DDE
