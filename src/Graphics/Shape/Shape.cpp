#include <DDE/Graphics/Shape/Shape.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
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
DDE::Shape::Shape(DDE::Vec4 color)
    : DDE::Drawable(DDE::ShaderStage::PRIMITIVE, color) {
  this->_initializeGLObjects();
}
