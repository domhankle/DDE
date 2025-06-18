#pragma once

#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <DDE/Utility/PositionTypes.hpp>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>

namespace DDE {

/**
 * @class Camera
 *
 * This class is intended to be used to represent a camera that
 * is looking at whatever is being rendered. It is responsible
 * for building the view matrix and is also what gives access to the
 * projection matrix.
 */
class Camera {

private:
  // The position of the camera
  glm::vec3 _position;
  // The direction from our target towards our camera
  glm::vec3 _direction;
  // The target position the camera is looking at
  glm::vec3 _target;
  // The up direction of the camera
  glm::vec3 _up;
  // The positive right direction from the camera
  glm::vec3 _right;
  // This defines the zone which are viewable by the camera
  DDE::Frustum _frustum;

  void _configureCamera(glm::vec3 position, glm::vec3 target);

public:
  Camera(glm::vec3 position = DDE::Z_AXIS_VECTOR,
         glm::vec3 target = DDE::ORIGIN, DDE::Frustum frustum = DDE::Frustum{});

  glm::mat4 getViewMatrix() const;
  glm::mat4 getProjectionMatrix() const;

  void setPosition(glm::vec3 position);
  glm::vec3 getPosition() const;

  void setTarget(glm::vec3 target);
  glm::vec3 getTarget() const;

  void setFrustum(DDE::Frustum &frustum);
  DDE::Frustum getFrustum() const;

  void translate(glm::vec3 translationVector);
};

}; // namespace DDE
