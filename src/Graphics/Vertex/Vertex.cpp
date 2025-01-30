#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <sstream>

/**
 * Constructor for Vertex object
 */
DDE::Vertex::Vertex(DDE::Vec4 position, DDE::Vec4 color,
                    DDE::Vec4 textureCoordinates)
    : position(position), color(color), textureCoordinates(textureCoordinates) {
}

/**
 * This is utilized to print a Vertex object to the console.
 *
 * @returns A string that represents the Vertex object
 */
std::string DDE::Vertex::print() const {
  std::stringstream ss;

  ss << "Position: " << this->position << "Color: " << this->color
     << "Texture Coordinates: " << this->textureCoordinates;

  return ss.str();
}
