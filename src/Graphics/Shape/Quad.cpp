#include "DDE/Graphics/Vertex/Vertex.hpp"
#include "Glad/glad/glad.h"
#include <DDE/Graphics/Shape/Quad.hpp>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <utility>

/**
 * Constructor for a Square shape. It handles constructing
 * the vertex data including the buffer objects and Vertex
 * Array object.
 */
DDE::Quad::Quad(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
                DDE::Vertex &vertexThree, DDE::Vertex &vertexFour)
    : Shape({vertexOne.x, vertexOne.y, vertexOne.z, vertexTwo.x, vertexTwo.y,
             vertexTwo.z, vertexThree.x, vertexThree.y, vertexThree.z,
             vertexFour.x, vertexFour.y, vertexFour.z}),
      _indices{0, 1, 4, 1, 2, 4, 2, 3, 4, 3, 0, 4} {

  std::vector<DDE::Vertex> vertices{vertexOne, vertexTwo, vertexThree,
                                    vertexFour};
  for (int i = 0; i < this->_vertices.size(); i += 3) {
    std::cout << "(" << this->_vertices[i] << ", " << this->_vertices[i + 1]
              << ", " << this->_vertices[i + 2] << ")\n";
  }
  std::cout << "----------------------" << std::endl;
  this->_vertices = this->_reorganizeVertices(vertices);

  for (int i = 0; i < this->_vertices.size(); i += 3) {
    std::cout << "(" << this->_vertices[i] << ", " << this->_vertices[i + 1]
              << ", " << this->_vertices[i + 2] << ")\n";
  }
  this->_setUpVertexData(this->_vertices);

  glBindVertexArray(0);
}

/**
 * This is the required render function that describes
 * how a Square object will be drawn to the screen.
 */
void DDE::Quad::render() {
  glBindVertexArray(this->_vertexArrayObject);
  glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
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

std::vector<float>
DDE::Quad::_reorganizeVertices(std::vector<DDE::Vertex> &vertices) {

  DDE::Vertex centroid = this->_getCentroidVertex(vertices);

  std::sort(
      vertices.begin(), vertices.end(),
      [&](DDE::Vertex vert1, DDE::Vertex vert2) { return vert1.y < vert2.y; });
  if (vertices.at(0).x == vertices.at(1).x) {
  }
  DDE::Vertex bottomLeft =
      vertices.at(0).x < vertices.at(1).x ? vertices.at(0) : vertices.at(1);
  DDE::Vertex topLeft =
      vertices.at(2).x < vertices.at(3).x ? vertices.at(2) : vertices.at(3);
  DDE::Vertex topRight =
      vertices.at(2).x > vertices.at(3).x ? vertices.at(2) : vertices.at(3);
  DDE::Vertex bottomRight =
      vertices.at(0).x > vertices.at(1).x ? vertices.at(0) : vertices.at(1);

  return std::vector<float>{
      bottomLeft.x,  bottomLeft.y,  bottomLeft.z, topLeft.x,     topLeft.y,
      topLeft.z,     topRight.x,    topRight.y,   bottomRight.z, bottomRight.x,
      bottomRight.y, bottomRight.z, centroid.x,   centroid.y,    centroid.z};
}

DDE::Vertex DDE::Quad::_getCentroidVertex(std::vector<DDE::Vertex> &vertices) {

  DDE::Vertex centroid;

  for (DDE::Vertex &vertex : vertices) {
    centroid.x += vertex.x;
    centroid.y += vertex.y;
    centroid.z += vertex.z;
  }

  centroid.x /= vertices.size();
  centroid.y /= vertices.size();
  centroid.z /= vertices.size();

  return centroid;
}
