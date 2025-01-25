#pragma once

#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <vector>

namespace DDE {

// TODO: Documentation
class VertexBuffer : public Buffer {

private:
  // TODO: Documentation
  std::vector<DDE::Vec4> _positionVertices;
  // TODO: Documentation
  DDE::Vec4 _color;

  void _configureBufferObject() override;
  void _configureVertexAttributes() override;
  std::vector<float> _getOpenGLData() override;

public:
  VertexBuffer() = default;
  VertexBuffer(std::vector<DDE::Vec4> positions,
               DDE::Vec4 color = DDE::Vec4{1.0f, 1.0f, 1.0f, 1.0f});
  void unBind() override;
  void bind() override;
};

} // namespace DDE
