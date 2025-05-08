#include "DDE/Engine/ShaderEngine.hpp"
#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <stdexcept>

// TODO: Documentation
DDE::Frustum::Frustum(DDE::FrustumType type, float xMin, float xMax, float yMin,
                      float yMax, float zMin, float zMax)
    : _type(type), _xMin(xMin), _xMax(xMax), _yMin(yMin), _yMax(yMax),
      _zMin(zMin), _zMax(zMax), _fov(0.0f), _aspectRatio(0.0f) {}

// TODO: Documentation
void DDE::Frustum::setType(DDE::FrustumType type) { this->_type = type; }

// TODO: Documentation
DDE::FrustumType DDE::Frustum::getType() const { return this->_type; }

// TODO: Documentation
void DDE::Frustum::setXClipMaximum(float xMax) { this->_xMax = xMax; }

// TODO: Documentation
float DDE::Frustum::getXClipMaximum() const { return this->_xMax; }

// TODO: Documentation
void DDE::Frustum::setXClipMinimum(float xMin) { this->_xMin = xMin; }

// TODO: Documentation
float DDE::Frustum::getXClipMinimum() const { return this->_xMin; }

// TODO: Documentation
void DDE::Frustum::setYClipMaximum(float yMax) { this->_yMax = yMax; }

// TODO: Documentation
float DDE::Frustum::getYClipMaximum() const { return this->_yMax; }

// TODO: Documentation
void DDE::Frustum::setYClipMinimum(float yMin) { this->_yMin = yMin; }

// TODO: Documentation
float DDE::Frustum::getYClipMinimum() const { return this->_yMin; }

// TODO: Documentation
void DDE::Frustum::setZClipMaximum(float zMax) { this->_zMax = zMax; }

// TODO: Documentation
float DDE::Frustum::getZClipMaximum() const { return this->_zMax; }

// TODO: Documentation
void DDE::Frustum::setZClipMinimum(float zMin) { this->_zMin = zMin; }

// TODO: Documentation
float DDE::Frustum::getZClipMinimum() const { return this->_zMin; }

// TODO: Documentation
void DDE::Frustum::setFOV(float fov) { this->_fov = fov; }

// TODO: Documentation
float DDE::Frustum::getFOV() const { return this->_fov; }

// TODO: Documentation
glm::mat4 DDE::Frustum::getProjectionMatrix() const {
  switch (this->_type) {
  case DDE::FrustumType::ORTHOGRAPHIC:
    return glm::ortho(this->_xMin, this->_xMax, this->_yMin, this->_yMax,
                      this->_zMin, this->_zMax);
  case DDE::FrustumType::PERSPECTIVE:
    return glm::perspective(this->_fov, this->_aspectRatio, this->_zMin,
                            this->_zMax);
  default:
    throw std::runtime_error("Invalid Frustum Type!");
  }
}
