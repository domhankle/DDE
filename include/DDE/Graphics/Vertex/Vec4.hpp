#pragma once

#include <ostream>

namespace DDE {

/**
 * @struct Vec4
 *
 * This struct is used to represent a point in space,
 * RGBA value, texture coordinates, etc. It essentially
 * can be used to represent any 1-4 component variable.
 */
struct Vec4 {
  // X value
  float x;

  // Y value
  float y;

  // Z value
  float z;

  // W value
  float w;

  Vec4(float x = 0.0, float y = 0.0, float z = 0.0, float w = 1.0);
  bool operator==(DDE::Vec4 &);
  std::string print() const;

  friend std::ostream &operator<<(std::ostream &os, const Vec4 &vector);
};

/**
 * This allows us to write Vec4 objects to an output stream
 * in a readable format.
 *
 * @param os The stream we are writing to.
 * @param vector The Vec4 object we are writing to the stream
 *
 * @returns An output stream that holds the Vec4 object
 */
inline std::ostream &operator<<(std::ostream &os, const DDE::Vec4 &vector) {
  os << vector.print();
  return os;
}

} // namespace DDE
