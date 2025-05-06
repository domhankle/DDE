#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <stdexcept>

// TODO: Documentation
DDE::Frustum::Frustum(DDE::FrustumType type, float xMin, float xMax, float yMin,
                      float yMax, float zMin, float zMax)
    : _type(type), _xMin(xMin), _xMax(xMax), _yMin(yMin), _yMax(yMax),
      _zMin(zMin), _zMax(zMax), _fov(45.0f) {}

// TODO: Documentation
void DDE::Frustum::setType(DDE::FrustumType type) { this->_type = type; }

// TODO: Documentation
void DDE::Frustum::setXClipMaximum(float xMax) { this->_xMax = xMax; }

// TODO: Documentation
void DDE::Frustum::setXClipMinimum(float xMin) { this->_xMin = xMin; }

// TODO: Documentation
void DDE::Frustum::setYClipMaximum(float yMax) { this->_yMax = yMax; }

// TODO: Documentation
void DDE::Frustum::setYClipMinimum(float yMin) { this->_yMin = yMin; }

// TODO: Documentation
void DDE::Frustum::setZClipMaximum(float zMax) { this->_zMax = zMax; }

// TODO: Documentation
void DDE::Frustum::setZClipMinimum(float zMin) { this->_zMin = zMin; }

// TODO: Documentation
void DDE::Frustum::setFOV(float fov) { this->_fov = fov; }

glm::mat4 DDE::Frustum::getProjectionMatrix() const {
  switch (this->_type) {
  case DDE::FrustumType::ORTHOGRAPHIC:
    return glm::ortho(this->_xMin, this->_xMax, this->_yMin, this->_yMax,
                      this->_zMin, this->_zMax);
  case DDE::FrustumType::PERSPECTIVE:
    throw std::runtime_error("Not Implemented!");
  default:
    throw std::runtime_error("Invalid Frustum Type!");
  }
}
