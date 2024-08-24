#pragma once

#include <vector>
namespace DDE {

// TODO: Documentation
class Buffer {

protected:
  // TODO: Documentation
  unsigned int _bufferObject;

private:
  virtual std::vector<float> _transformToOpenGLData() = 0;
  virtual void _configureBufferObject() = 0;
  virtual void _configureVertexAttributes() = 0;

public:
  Buffer();
  virtual void unBind() = 0;
  virtual void bind() = 0;
};

} // namespace DDE
