#include <DDE/Graphics/Shape/Shape.hpp>
#include <Glad/glad/glad.h>

/**
 * This private function is used to create our
 * VAO and VBO associated with this Triangle object.
 */
void DDE::Shape::_initializeGLObjects() {
  glGenVertexArrays(1, &this->_vertexArrayObject);
  glBindVertexArray(this->_vertexArrayObject);
}

/**
 * The constructor for a Shape object only accepts
 * vertex data.
 */
DDE::Shape::Shape(std::initializer_list<float> vertices)
    : _vertices{vertices}, Drawable(DDE::ShaderStage::PRIMITIVE) {
  this->_initializeGLObjects();
}
