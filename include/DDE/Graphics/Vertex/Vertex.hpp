#pragma once

#include "glm/fwd.hpp"
#include <glm/glm.hpp>
#include <ostream>

namespace DDE {

/**
 * @struct Vertex
 *
 * This is utilized to represent a single vertex
 * in the context of OpenGL. A vertex could hold
 * position, color, and texture coordinates.
 */
struct Vertex {

  friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);

private:
  std::string _print() const;

public:
  glm::vec4 position;
  glm::vec4 color;
  glm::vec4 texture;

  Vertex(glm::vec4 position = glm::vec4{}, glm::vec4 color = glm::vec4{},
         glm::vec4 texture = glm::vec4{});
};

/**
 * This allows us to write Vertex objects to an output stream
 * in a readable format.
 *
 * @param os The stream we are writing to.
 * @param vertex The vertex object we are writing to the stream
 *
 * @returns An output stream that holds the vertex object
 */
inline std::ostream &operator<<(std::ostream &os, const DDE::Vertex &vertex) {
  os << vertex._print();
  return os;
}

} // namespace DDE
