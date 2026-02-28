#include <DDE/Graphics/Buffer/VertexBuffer.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>

/**
 * Triangle base/height constructor
 *
 * @param base The length of the base of the triangle
 * @param height The height of the triangle
 * @param color An optional RGBA color for the triangle. It defaults to solid
 * white
 */
DDE::Triangle::Triangle(float base, float height, glm::vec4 color)
    : DDE::Shape(color), _base(base), _height(height) {
  this->_setUpVertexData(this->_vertexBuffer);
}

/**
 * This is a helper function to construct vertices
 * that can be used by OpenGL from a triangles height
 * and base.
 *
 * @param vbo This is the vertex buffer object we need to store the vertices in
 */
void DDE::Triangle::_setUpVertexData(DDE::VertexBuffer &vbo) {
  // Create a vector to store our Vertex objects
  std::vector<DDE::Vertex> vertices;

  // Create a vector to store three glm::vec4 objects (x, y, z) for position
  std::vector<glm::vec4> positions;

  // Store the positions of the triangle based on the height and base values
  positions.push_back(
      glm::vec4{-this->_base / 2, -this->_height / 2, 0.0f, 1.0f});
  positions.push_back(
      glm::vec4{this->_base / 2, -this->_height / 2, 0.0f, 1.0f});
  positions.push_back(glm::vec4{0.0f, this->_height / 2, 0.0f, 1.0f});

  // Create Vertex objects based on the glm::vec4 objects
  for (glm::vec4 &position : positions) {
    vertices.push_back(DDE::Vertex{position, this->_color});
  }

  // Create our VertexBuffer object
  vbo = DDE::VertexBuffer{vertices};

  // Unbind the VAO associated with this triangle
  glBindVertexArray(0);
}

/**
 * This function is used to actually render
 * the triangle object to the screen.
 */
void DDE::Triangle::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
