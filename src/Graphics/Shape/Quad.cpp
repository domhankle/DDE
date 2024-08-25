#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <algorithm>

/**
 * Constructor for a Square shape based on width/height. The
 * origin of this shape will be located in the center of the
 * screen.
 *
 * @param width The horizontal width of the shape
 * @param height The vertical height of the shape
 */
DDE::Quad::Quad(float width, float height)
    : Shape(), _indices{0, 1, 2, 1, 2, 3} {

  this->_vertices = this->_reorganizeVertices(
      {DDE::Vertex(-width / 2, -height / 2),
       DDE::Vertex(width / 2, -height / 2), DDE::Vertex(width / 2, height / 2),
       DDE::Vertex(-width / 2, height / 2)});

  this->_setUpVertexData(this->_vertices);

  glBindVertexArray(0);
}

/**
 * This is the required render function that describes
 * how a Square object will be drawn to the screen.
 */
void DDE::Quad::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/**
 * This is a helper private function used to help construct
 * the element buffer object associated with square objects.
 *
 * @param indices The list of indices to draw from our vertex data.
 */
void DDE::Quad::_setUpElementsBuffer(std::vector<unsigned int> &indices) {
  glGenBuffers(1, &this->_elementBufferObject);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_elementBufferObject);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               this->_indices.size() * sizeof(unsigned int),
               this->_indices.data(), GL_STATIC_DRAW);
}

/**
 * This is used to set up and describe our vertex data associated
 * with our Square object.
 *
 * @param vertices A list of floats representing drawing data for our Square
 */
void DDE::Quad::_setUpVertexData(std::vector<float> &vertices) {

  glGenBuffers(1, &this->_vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, this->_vertexBufferObject);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  this->_setUpElementsBuffer(this->_indices);
}

/**
 * This function handles creating a vector of floats that
 * represents the vertices in such a way we can guarantee
 * the quad will NOT be rendered in a way where the two triangles
 * used to make it intersect eachother.
 *
 * @param vertices The vertices passed to create this quad
 * @returns A vector of floats representing the properly ordered vertices
 */
std::vector<float>
DDE::Quad::_reorganizeVertices(std::vector<DDE::Vertex> &&vertices) {

  // Sort the vector in ascending order based on vertices y values
  std::sort(vertices.begin(), vertices.end(),
            [&](DDE::Vertex vert1, DDE::Vertex vert2) {
              return std::min(vert1.y, vert2.y);
            });

  // Define the four main point of the quad
  DDE::Vertex bottomLeft =
      vertices.at(0).x < vertices.at(1).x ? vertices.at(0) : vertices.at(1);
  DDE::Vertex topLeft =
      vertices.at(2).x < vertices.at(3).x ? vertices.at(2) : vertices.at(3);
  DDE::Vertex topRight =
      vertices.at(2).x > vertices.at(3).x ? vertices.at(2) : vertices.at(3);
  DDE::Vertex bottomRight =
      vertices.at(0).x > vertices.at(1).x ? vertices.at(0) : vertices.at(1);

  // Return a vector of floats with the proper ordering of the coordinates
  return std::vector<float>{bottomLeft.x,  bottomLeft.y,  bottomLeft.z,
                            topLeft.x,     topLeft.y,     topLeft.z,
                            bottomRight.x, bottomRight.y, bottomRight.z,
                            topRight.x,    topRight.y,    topRight.z};
}
