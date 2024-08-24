#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <Glad/glad/glad.h>

// TODO: Documentation
DDE::Buffer::Buffer() { glGenBuffers(1, &this->_bufferObject); }
