#include "glm/ext/matrix_transform.hpp"
#include <DDE/Graphics/Drawable.hpp>

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
      _modelMatrix(glm::mat4(1.0f)) {}

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
void DDE::Drawable::translate(glm::vec3 directionVector) {
  this->_modelMatrix = glm::translate(this->_modelMatrix, directionVector);
}

// TODO: Documentation
void DDE::Drawable::rotate(float degrees, glm::vec3 rotationVector) {
  this->_modelMatrix = glm::rotate(this->_modelMatrix, degrees, rotationVector);
}

// TODO: Documentation
void DDE::Drawable::scale(glm::vec3 scaleVector) {
  this->_modelMatrix = glm::scale(this->_modelMatrix, scaleVector);
}
