#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <sstream>

/**
 * Constructor for Vertex object
 */
DDE::Vertex::Vertex(DDE::Vec4 position, DDE::Vec4 color,
                    DDE::Vec4 textureCoordinates)
    : position(position), color(color), textureCoordinates(textureCoordinates) {
}

// TODO: Documentation
std::string DDE::Vertex::print() const {
  std::stringstream ss;

  ss << "Position: " << this->position << std::endl
     << "Color: " << this->color << std::endl
     << "Texture Coordinates: " << this->textureCoordinates << std::endl;

  return ss.str();
}

/**
 * Constructor for Vec4 object
 */
DDE::Vec4::Vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

// TODO: Documentation
bool DDE::Vec4::operator==(DDE::Vec4 &rhs) {
  return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z &&
         this->w == rhs.w;
}

// TODO: Documentation
std::string DDE::Vec4::print() const {

  std::stringstream ss;
  ss << "( " << this->x << ", " << this->y << ", " << this->z << ", " << this->w
     << ")" << std::endl;

  return ss.str();
}
