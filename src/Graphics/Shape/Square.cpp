#include <DDE/Graphics/Shape/Square.hpp>

DDE::Square::Square(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
                    DDE::Vertex &vertexThree, DDE::Vertex &vertexFour)
    : Shape({vertexOne.x, vertexOne.y, vertexOne.z, vertexTwo.x, vertexTwo.y,
             vertexTwo.z, vertexThree.x, vertexThree.y, vertexThree.z,
             vertexFour.x, vertexFour.y, vertexFour.z}) {

  this->_setUpVertexData(this->_vertices);

  glBindVertexArray(0);
}

void DDE::Square::render() { glBindVertexArray(this->_vertexArrayObject); }

void DDE::Square::_setUpVertexData(std::vector<float> &vertices) {}
