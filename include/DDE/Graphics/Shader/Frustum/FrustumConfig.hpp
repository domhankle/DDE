#pragma once

#include <DDE/Graphics/Shader/Frustum/FrustumTypes.hpp>

namespace DDE {

/**
 * @class FrustumConfig
 *
 * This config object is used to hold the data that
 * is associated with a Frustum object. This config can
 * hold data for either an Orthographic frustum or a
 * Perspective frustum.
 */
struct FrustumConfig {

  // Orthographic or Perspective
  DDE::FrustumType type;

  // The minimum x clip value
  float xMin;
  // The maximum x clip value
  float xMax;

  // The minimum y clip value
  float yMin;
  // The maximum y clip value
  float yMax;

  // The minimum z clip value
  float zMin;
  // The maximum z clip value
  float zMax;

  // The FOV
  float fov;

  // Aspect ratio
  float aspectRatio;

  FrustumConfig(DDE::FrustumType type = DDE::FrustumType::ORTHOGRAPHIC,
                float xMin = -100.0f, float xMax = 100.0f, float yMin = -100.0f,
                float yMax = 100.0f, float zMin = 0.0f, float zMax = 100.0f,
                float fov = 0.0f, float aspectRatio = 0.0f);
};

}; // namespace DDE
