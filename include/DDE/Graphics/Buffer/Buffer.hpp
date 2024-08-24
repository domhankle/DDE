#pragma once

namespace DDE {

// TODO: Documentation
class Buffer {

private:
  // TODO: Documentation
  unsigned int _bufferObject;

protected:
  void _configureBufferObject();

public:
  Buffer() = delete;
  Buffer(unsigned int bufferType);
};

} // namespace DDE
