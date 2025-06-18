#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <stdexcept>

/**
 * This is our constructor for a Frustum object
 *
 * @param config The FrustumConfig object associated with this Frustum
 */
DDE::Frustum::Frustum(DDE::FrustumConfig config) : _config(config) {}

/**
 * Used to dynamically change the type of the Frustum. This will impact
 * the return value of DDE::Frustum::getProjectionMatrix. Frustums of
 * type PERSPECTIVE expect the fov and aspectRatio property to be set.
 *
 * @param type The new Frustum type
 */
void DDE::Frustum::setType(DDE::FrustumType type) { this->_config.type = type; }

/**
 * This function is used to get the Frustum type
 *
 * @returns The type of the Frustum (ORTHOGRAPHIC/PERSPECTIVE)
 */
DDE::FrustumType DDE::Frustum::getType() const { return this->_config.type; }

/**
 * Used to dynamically change the maximum x clip value of a Frustum.
 *
 * @param xMax The new maximum x clip value
 */
void DDE::Frustum::setXClipMaximum(float xMax) { this->_config.xMax = xMax; }

/**
 * This function is used to get the xMax property on the Frustum
 *
 * @returns The xMax property
 */
float DDE::Frustum::getXClipMaximum() const { return this->_config.xMax; }

/**
 * Used to dynamically change the minimum x clip value of a Frustum.
 *
 * @param xMin The new minimum x clip value
 */
void DDE::Frustum::setXClipMinimum(float xMin) { this->_config.xMin = xMin; }

/**
 * This function is used to get the xMin property on the Frustum
 *
 * @returns The xMin property
 */
float DDE::Frustum::getXClipMinimum() const { return this->_config.xMin; }

/**
 * Used to dynamically change the maximum y clip value of a Frustum.
 *
 * @param yMax The new maximum y clip value
 */
void DDE::Frustum::setYClipMaximum(float yMax) { this->_config.yMax = yMax; }

/**
 * This function is used to get the yMax property on the Frustum
 *
 * @returns The yMax property
 */
float DDE::Frustum::getYClipMaximum() const { return this->_config.yMax; }

/**
 * Used to dynamically change the minimum y clip value of a Frustum.
 *
 * @param yMin The new minimum y clip value
 */
void DDE::Frustum::setYClipMinimum(float yMin) { this->_config.yMin = yMin; }

/**
 * This function is used to get the yMin property on the Frustum
 *
 * @returns The yMin property
 */
float DDE::Frustum::getYClipMinimum() const { return this->_config.yMin; }

/**
 * Used to dynamically change the maximum z clip value of a Frustum.
 *
 * @param zMax The new maximum z clip value
 */
void DDE::Frustum::setZClipMaximum(float zMax) { this->_config.zMax = zMax; }

/**
 * This function is used to get the zMax property on the Frustum
 *
 * @returns The zMax property
 */
float DDE::Frustum::getZClipMaximum() const { return this->_config.zMax; }

/**
 * Used to dynamically change the minimum z clip value of a Frustum.
 *
 * @param zMax The new minimum z clip value
 */
void DDE::Frustum::setZClipMinimum(float zMin) { this->_config.zMin = zMin; }

/**
 * This function is used to get the zMin property on the Frustum
 *
 * @returns The zMin property
 */
float DDE::Frustum::getZClipMinimum() const { return this->_config.zMin; }

/**
 * Used to dynamically change the FOV of a Frustum.
 *
 * @param fov The new FOV of the Frustum
 */
void DDE::Frustum::setFOV(float fov) { this->_config.fov = fov; }

/**
 * This function is used to get the FOV property on the Frustum
 *
 * @returns The FOV of the Frustum
 */
float DDE::Frustum::getFOV() const { return this->_config.fov; }

/**
 * Used to dynamically change the aspect ratio of a Frustum
 *
 * @param aspectRatio The new apect ratio of the Frustum
 */
void DDE::Frustum::setAspectRatio(float aspectRatio) {
  this->_config.aspectRatio = aspectRatio;
}

/**
 * This function is used to get the aspectRatio property on the Frustum
 *
 * @returns The aspect ratio of the Frustum
 */
float DDE::Frustum::getAspectRatio() const { return this->_config.aspectRatio; }

/**
 * Used to dynamically change the config object of a Frustum.
 *
 * @param config The new config object
 */
void DDE::Frustum::setConfig(DDE::FrustumConfig &config) {
  this->_config = config;
}

/**
 * This function is used to get the FrustumConfig object associated
 * with a Frustum.
 */
DDE::FrustumConfig DDE::Frustum::getConfig() const { return this->_config; }

/**
 * This function handles retrieving the projection matrix associated
 * with a Frustum object.
 *
 * @returns A glm::mat4 that represents the projection of a Frustum.
 */
glm::mat4 DDE::Frustum::getProjectionMatrix() const {
  switch (this->_config.type) {
  case DDE::FrustumType::ORTHOGRAPHIC:
    return glm::ortho(this->_config.xMin, this->_config.xMax,
                      this->_config.yMin, this->_config.yMax,
                      this->_config.zMin, this->_config.zMax);
  case DDE::FrustumType::PERSPECTIVE:
    return glm::perspective(this->_config.fov, this->_config.aspectRatio,
                            this->_config.zMin, this->_config.zMax);
  default:
    throw std::runtime_error("Invalid Frustum Type!");
  }
}
