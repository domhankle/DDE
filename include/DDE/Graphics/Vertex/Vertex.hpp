#pragma once

#include <DDE/Graphics/Vertex/Vec4.hpp>
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
  DDE::Vec4 position;
  DDE::Vec4 color;
  DDE::Vec4 texture;

  Vertex(DDE::Vec4 position = DDE::Vec4(),
         DDE::Vec4 color = DDE::Vec4(1.0f, 1.0f, 1.0f, 1.0f),
         DDE::Vec4 texture = DDE::Vec4());
  std::string print() const;

  friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
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
  os << vertex.print();
  return os;
}

} // namespace DDE
