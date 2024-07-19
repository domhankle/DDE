#include <DDE/Graphics/Shape/Triangle.hpp>

/**
 * Triangle constructor
 *
 * @param vertexOne The first vertex of the triangle
 * @param vertexTwo The second vertex of the triangle
 * @param vertexThree The third vertex of the triangle
 */
DDE::Triangle::Triangle(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
                        DDE::Vertex &vertexThree)
    : Shape({vertexOne.x, vertexOne.y, vertexOne.z, vertexTwo.x, vertexTwo.y,
             vertexTwo.z, vertexThree.x, vertexThree.y, vertexThree.z}) {

  this->_setUpVertexData(this->_vertices);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
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

/**
 * This function is used to configure our VBO
 * and specify the layout of our vertex data
 * for the Triangle object.
 *
 * @param vertices The set of vertices associated with
 *                 this Triangle object
 */
void DDE::Triangle::_setUpVertexData(std::vector<float> &vertices) {
  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);

  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
}
