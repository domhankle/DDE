#pragma once

namespace DDE {

/**
 * @struct Vertex
 *
 * This struct is used to represent a point in space,
 * RGBA value, texture coordinates, etc. It essentially
 * can be used to represent any 1-4 component variable.
 */
struct Vertex {
  // X value
  float x;

  // Y value
  float y;

  // Z value
  float z;

  // W value
  float w;

  Vertex(float x = 0.0, float y = 0.0, float z = 0.0, float w = 1.0);
  bool operator==(DDE::Vertex &);
};

} // namespace DDE
