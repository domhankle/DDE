#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <sstream>

/**
 * Constructor for Vertex object
 */
DDE::Vertex::Vertex(glm::vec4 position, glm::vec4 color, glm::vec4 texture)
    : position(position), color(color), texture(texture) {}

/**
 * This is utilized to print a Vertex object to the console.
 *
 * @returns A string that represents the Vertex object
 */
std::string DDE::Vertex::_print() const {
  std::stringstream ss;

  ss << "Position: (" << this->position.x << ", " << this->position.y << ", "
     << this->position.z << ", " << this->position.w << ")\n"
     << "Color: (" << this->color.x << ", " << this->color.y << ", "
     << this->color.z << ", " << this->color.w << ")\n"
     << "Texture: (" << this->texture.x << ", " << this->texture.y << ", "
     << this->texture.z << ", " << this->texture.w << ")\n";

  return ss.str();
}
