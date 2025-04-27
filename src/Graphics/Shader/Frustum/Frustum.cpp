#include <DDE/Graphics/Shader/Frustum/Frustum.hpp>
#include <glm/ext/matrix_clip_space.hpp>

// TODO: Documentation
DDE::Frustum::Frustum(float xMin, float xMax, float yMin, float yMax,
                      float zMin, float zMax)
    : _xMin(xMin), _xMax(xMax), _yMin(yMin), _yMax(yMax), _zMin(zMin),
      _zMax(zMax),
      _projectionMatrix(glm::ortho(xMin, xMax, yMin, yMax, zMin, zMax)) {}

// TODO: Documentation
glm::mat4 DDE::Frustum::getProjectionMatrix() const {
  return this->_projectionMatrix;
}

// TODO: Documentation
void DDE::Frustum::setZClipMaximum(float zMax) { this->_zMax = zMax; }

// TODO: Documentation
void DDE::Frustum::setZClipMinimum(float zMin) { this->_zMin = zMin; }
