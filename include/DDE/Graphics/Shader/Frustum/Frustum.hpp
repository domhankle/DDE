#pragma once
#include <glm/glm.hpp>

namespace DDE {

// TODO: Documentation
class Frustum {
private:
  float _xMin;
  float _xMax;

  float _yMin;
  float _yMax;

  float _zMin;
  float _zMax;

  glm::mat4 _projectionMatrix;

public:
  Frustum(float xMin = -100.0f, float xMax = 100.0f, float yMin = -100.0f,
          float yMax = 100.0f, float zMin = 0.0f, float zMax = 100.0f);

  glm::mat4 getProjectionMatrix() const;

  void setZClipMinimum(float zMin);
  void setZClipMaximum(float zMax);
};
} // namespace DDE
