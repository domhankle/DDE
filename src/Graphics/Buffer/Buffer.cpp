#include <DDE/Graphics/Buffer/Buffer.hpp>
#include <Glad/glad/glad.h>

/**
 * Default constructor for all DDE::Buffer objects
 */
DDE::Buffer::Buffer() { glGenBuffers(1, &this->_bufferObject); }
