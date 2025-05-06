#include "glm/fwd.hpp"
#include <DDE/Graphics/Shader/Frustum/FrustumTypes.hpp>

namespace DDE {
/**
 * @class Frustum
 *
 * The frustum is a rendering space that will be viewable by the user.
 * Anything that falls outside the space defined by the frustum class
 * is clipped by OpenGL and will not be viewable. A frustum is used
 * to generate the default projection matrix everytime
 * ShaderEngine::ActivateShader is called. This matrix can be updated afterwards
 * with ShaderEngine::UpdateProjectionMatrix. The attached Frustum to the
 * ShaderEngine can be updated with ShaderEngine::UpdateFrustum.
 */
class Frustum {
private:
  float _xMin;
  float _xMax;

  float _yMin;
  float _yMax;

  float _zMin;
  float _zMax;

  float _fov;

  DDE::FrustumType _type;

public:
  Frustum(DDE::FrustumType type = DDE::FrustumType::ORTHOGRAPHIC,
          float xMin = -100.0f, float xMax = 100.0f, float yMin = -100.0f,
          float yMax = 100.0f, float zMin = 0.0f, float zMax = 100.0f);

  glm::mat4 getProjectionMatrix() const;

  void setType(DDE::FrustumType type);

  void setXClipMinimum(float xMin);
  void setXClipMaximum(float xMax);

  void setYClipMinimum(float yMin);
  void setYClipMaximum(float yMax);

  void setZClipMinimum(float zMin);
  void setZClipMaximum(float zMax);

  void setFOV(float fov);
};

} // namespace DDE
