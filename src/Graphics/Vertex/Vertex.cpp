#include <DDE/Graphics/Vertex/Vertex.hpp>

/**
 * Constructor for Vertex object
 */
DDE::Vertex::Vertex(float x, float y, float z, float w)
    : x{x}, y{y}, z{z}, w{w} {}

bool DDE::Vertex::operator==(DDE::Vertex &rhs) {
  return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z &&
         this->w == rhs.w;
}
