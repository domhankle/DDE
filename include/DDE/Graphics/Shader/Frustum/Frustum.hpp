#pragma once

#include <DDE/Graphics/Shader/Frustum/FrustumConfig.hpp>
#include <DDE/Graphics/Shader/Frustum/FrustumTypes.hpp>
#include <glm/fwd.hpp>

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
  DDE::FrustumConfig _config;

public:
  Frustum(DDE::FrustumConfig config = DDE::FrustumConfig{});

  glm::mat4 getProjectionMatrix() const;

  void setType(DDE::FrustumType type);
  DDE::FrustumType getType() const;

  void setXClipMinimum(float xMin);
  float getXClipMinimum() const;

  void setXClipMaximum(float xMax);
  float getXClipMaximum() const;

  void setYClipMinimum(float yMin);
  float getYClipMinimum() const;

  void setYClipMaximum(float yMax);
  float getYClipMaximum() const;

  void setZClipMinimum(float zMin);
  float getZClipMinimum() const;

  void setZClipMaximum(float zMax);
  float getZClipMaximum() const;

  void setFOV(float fov);
  float getFOV() const;

  void setAspectRatio(float aspectRatio);
  float getAspectRatio() const;

  void setConfig(DDE::FrustumConfig &config);
  DDE::FrustumConfig getConfig() const;
};

} // namespace DDE
