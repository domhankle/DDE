#include "DDE/Graphics/Vertex/Vertex.hpp"
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <iostream>
#include <ostream>

/**
 * Triangle vertex constructor
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

  glBindVertexArray(0);
}

/**
 * Triangle base/height constructor
 *
 * @param base The length of the base of the triangle
 * @param height The height of the triangle
 */
DDE::Triangle::Triangle(float base, float height)
    : Shape({-base / 2, -height / 2, 0.0f, base / 2, -height / 2, 0.0f, 0.0f,
             height / 2, 0.0f}) {
  std::vector<DDE::Vertex> positions;
  positions.push_back(DDE::Vertex{-base / 2, -height / 2});
  positions.push_back(DDE::Vertex{base / 2, -height / 2});
  positions.push_back(DDE::Vertex{0.0f, height / 2});
  this->_vertexBuffer =
      VertexBuffer{positions, DDE::Vertex{1.0f, 0.0f, 0.0f, 1.0f}};
  glBindVertexArray(0);
}

/**
 * This function is used to actually render
 * the triangle object to the screen.
 */
void DDE::Triangle::render() {
  // std::cout << "Called Render!" << std::endl;
  // exit(EXIT_FAILURE);
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
