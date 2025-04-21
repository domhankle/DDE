#include <DDE/Graphics/Drawable.hpp>
#include <DDE/Graphics/Vertex/Vec4.hpp>
#include <glm/ext/matrix_transform.hpp>

/**
 * The constructor is simply used to specify the shader pipeline
 * used by this drawable object. A color can be optionally provided
 * for this Drawable object.
 *
 * @param shaderPipeline The shader stage in which this drawable object should
 * be drawn
 * @param color The RGBA of this drawable object
 */
DDE::Drawable::Drawable(DDE::ShaderStage shaderPipeline, DDE::Vec4 color)
    : _shaderPipelineID(shaderPipeline), _color(color),
      _modelMatrix(glm::mat4(1.0f)), _position{0, 0, 0, 0},
      _size{1.0, 1.0, 1.0, 1.0} {}

/**
 * This is our function to get the shader pipeline ID from
 * a drawable object in DDE.
 */
DDE::ShaderStage DDE::Drawable::getShaderPipeline() const {
  return this->_shaderPipelineID;
}

// TODO:Documentation
glm::mat4 DDE::Drawable::getModelMatrix() const { return this->_modelMatrix; }

// TODO: Documentation
DDE::Vec4 DDE::Drawable::getPosition() const { return this->_position; }

// TODO: Documentation
DDE::Vec4 DDE::Drawable::getSize() const { return this->_size; }

// TODO: Documentation
void DDE::Drawable::translate(glm::vec3 directionVector) {
  // TODO: Documentation/Change how we do this
  this->_position.x += directionVector.x;
  this->_position.y += directionVector.y;
  this->_position.z += directionVector.z;

  this->_modelMatrix = glm::translate(this->_modelMatrix, directionVector);
}

// TODO: Documentation
void DDE::Drawable::rotate(float degrees, glm::vec3 rotationVector) {
  this->_modelMatrix = glm::rotate(this->_modelMatrix, degrees, rotationVector);
}

// TODO: Documentation
void DDE::Drawable::scale(glm::vec3 scaleVector) {
  // TODO: Documentation/Change how we do this
  this->_size.x *= scaleVector.x;
  this->_size.y *= scaleVector.y;
  this->_size.z *= scaleVector.z;

  this->_modelMatrix = glm::scale(this->_modelMatrix, scaleVector);
}
