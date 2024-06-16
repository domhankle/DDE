#pragma once

namespace DDE {

struct Vertex {
  float x;
  float y;
  float z;
  float w;

  Vertex(float x = 0.0, float y = 0.0, float z = 0.0, float w = 1.0);
};

} // namespace DDE
