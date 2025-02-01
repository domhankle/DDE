#pragma once

#include <vector>
namespace DDE {

/**
 * @class Buffer
 *
 * This class is a base buffer class that
 * the VertexBuffer object extends off of. It
 * is utilized to generate buffer objects in OpenGL.
 */
class Buffer {

protected:
  // The underlying OpenGL buffer object
  unsigned int _bufferObject;

private:
  virtual std::vector<float> _getOpenGLData() = 0;
  virtual void _configureBufferObject() = 0;
  virtual void _configureVertexAttributes() = 0;

public:
  Buffer();
  virtual void unBind() = 0;
  virtual void bind() = 0;
};

} // namespace DDE
