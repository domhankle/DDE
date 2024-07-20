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
 * The default Shape constructor is utilized when
 * we want to handle constructing vertices in an
 * inheriting Shape class like Quad.
 */
DDE::Shape::Shape()
    : _vertices{{}}, DDE::Drawable(DDE::ShaderStage::PRIMITIVE) {
  this->_initializeGLObjects();
}

/**
 * The constructor for a Shape object only accepts
 * vertex data.
 *
 * @param vertices The vertex data
 */
DDE::Shape::Shape(std::initializer_list<float> vertices)
    : _vertices{vertices}, DDE::Drawable(DDE::ShaderStage::PRIMITIVE) {
  this->_initializeGLObjects();
}
