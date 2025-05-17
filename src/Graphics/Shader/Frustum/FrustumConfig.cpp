#include <DDE/Graphics/Shader/Frustum/FrustumConfig.hpp>

/**
 * This is our constructor for the FrustumConfig object
 *
 * TODO: We should inject the aspect ratio, not specify it in constructor
 * (DDE-40)
 *
 * @param type Orthographic or Perspective
 * @param xMin Minimum x clip value of Frustum
 * @param xMax Maximum x clip value of Frustum
 * @param yMin Minimum y clip value of Frustum
 * @param yMax Maximum y clip value of Frustum
 * @param zMin Minimum z clip value of Frustum
 * @param zMax Maximum z clip value of Frustum
 * @param fov The field of view for the Frustum
 * @param aspectRatio The aspect ratio of the screen
 */
DDE::FrustumConfig::FrustumConfig(DDE::FrustumType type, float xMin, float xMax,
                                  float yMin, float yMax, float zMin,
                                  float zMax, float fov, float aspectRatio)
    : type(type), xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax), zMin(zMin),
      zMax(zMax), fov(fov), aspectRatio(aspectRatio) {}
