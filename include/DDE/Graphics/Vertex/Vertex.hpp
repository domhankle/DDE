#pragma once

namespace DDE {

/**
 * @struct Vertex
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
};

// TODO: Documentation
struct Vertex {
  DDE::Vec4 position;
  DDE::Vec4 color;
  DDE::Vec4 textureCoordinates;

  Vertex(DDE::Vec4 position = DDE::Vec4(), DDE::Vec4 color = DDE::Vec4(),
         DDE::Vec4 textureCoordinates = DDE::Vec4());
};

} // namespace DDE
