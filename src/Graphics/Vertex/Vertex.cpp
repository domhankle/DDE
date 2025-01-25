#include <DDE/Graphics/Vertex/Vertex.hpp>

/**
 * Constructor for Vec4 object
 */
DDE::Vec4::Vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

/**
 * Constructor for Vertex object
 */
DDE::Vertex::Vertex(DDE::Vec4 position, DDE::Vec4 color,
                    DDE::Vec4 textureCoordinates)
    : position(position), color(color), textureCoordinates(textureCoordinates) {
}

// TODO: Documentation
bool DDE::Vec4::operator==(DDE::Vec4 &rhs) {
  return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z &&
         this->w == rhs.w;
}
