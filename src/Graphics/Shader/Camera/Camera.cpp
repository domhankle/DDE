#include <DDE/Graphics/Shader/Camera/Camera.hpp>
#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/geometric.hpp>

/**
 * This is the Constructor for a Camera object
 *
 * @param position The position of the camera
 * @param target The target object the camera is looking at
 * @param frustum The "viewing" bounds for the camera
 */
DDE::Camera::Camera(glm::vec3 position, glm::vec3 target, DDE::Frustum frustum)
    : _position(position), _target(target), _frustum(frustum) {
  this->_configureCamera(this->_position, this->_target);
}

/**
 * This is an internal function used to do some additional configuration
 * of the Camera object after receiving the position, target, and frustum.
 *
 * @param position The position of the camera
 * @param target The target that the camera is looking at
 */
void DDE::Camera::_configureCamera(glm::vec3 position, glm::vec3 target) {
  // This will point from our target at through our camera
  this->_direction = glm::normalize(this->_position - this->_target);
  // (0, 1, 0) and _direction will give us the right vector out from the camera
  this->_right =
      glm::normalize(glm::cross(DDE::Y_AXIS_VECTOR, this->_direction));
  // This will give us the up vector from the camera
  this->_up = glm::normalize(glm::cross(this->_direction, this->_right));
}

/**
 * This returns the viewing matrix associated with this camera
 *
 * @returns The view matrix
 */
glm::mat4 DDE::Camera::getViewMatrix() const {
  return glm::lookAt(this->_position, this->_target, this->_up);
}

/**
 * This return the projection matrix associated with this camera's
 * frustum.
 *
 * @returns The projection matrix
 */
glm::mat4 DDE::Camera::getProjectionMatrix() const {
  return this->_frustum.getProjectionMatrix();
}

/**
 * This is used to set the target position the camera is looking at.
 *
 * @param target The target position you are setting
 */
void DDE::Camera::setTarget(glm::vec3 target) { this->_target = target; }

/**
 * This is used to get the target position a camera is looking at.
 *
 * @returns The target position the Camera is looking at
 */
glm::vec3 DDE::Camera::getTarget() const { return this->_target; }

/**
 * This is used to set the position of the camera.
 *
 * @param position The position you are setting
 */
void DDE::Camera::setPosition(glm::vec3 position) {
  this->_position = position;
}

/**
 * This is used to get the position of a camera.
 *
 * @returns The position of the Camera
 */
glm::vec3 DDE::Camera::getPosition() const { return this->_position; }

/**
 * This is used to set the frustum of the camera.
 */
void DDE::Camera::setFrustum(DDE::Frustum &frustum) {
  this->_frustum = frustum;
}

/**
 * This is used to get the frustum of a camera.
 *
 * @returnts The frustum associated with the Camera
 */
DDE::Frustum DDE::Camera::getFrustum() const { return this->_frustum; }

/**
 * This is used to move a camera somewhere in space while having it
 * maintain the same orientation. This means the target position the camera
 * looks at will be moved in parallel with the camera position.
 *
 * @param translationVector This will hold the direction and magnitude in which
 *                          the camera moves
 */
void DDE::Camera::translate(glm::vec3 translationVector) {
  this->_position += translationVector;
  this->_target += translationVector;
}
