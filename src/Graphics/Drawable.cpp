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
    : _shaderPipelineID(shaderPipeline), _color(color), _modelMatrix{1.0f},
      _position{0.0f}, _scale{1.0f} {}

/**
 * This is our function to get the shader pipeline ID from
 * a drawable object in DDE.
 */
DDE::ShaderStage DDE::Drawable::getShaderPipeline() const {
  return this->_shaderPipelineID;
}

/**
 * Getter for the model matrix of a drawable object.
 *
 * @returns The model matrix of this drawable object
 */
glm::mat4 DDE::Drawable::getModelMatrix() const { return this->_modelMatrix; }

/**
 * Getter for the current position of a drawable object.
 *
 * @returns The current position of a drawable object as a vec3
 */
glm::vec3 DDE::Drawable::getPosition() const { return this->_position; }

/**
 * Getter for the current scaling of a drawable object on each axis.
 *
 * @returns The current scaling for each axis of the drawable object as a vec3
 */
glm::vec3 DDE::Drawable::getScale() const { return this->_scale; }

/**
 * This function is utilized to translate a drawable object in space.
 *
 * @param translationVector The (x, y, z) coordinate direction to translate.
 *                          The magnitude is included in this vector, it does
 *                          not have to be a unit vector.
 */
void DDE::Drawable::translate(glm::vec3 translationVector) {
  // Add the translation vector to our position vector of this object
  this->_position += translationVector;

  // Translate the model matrix for the object
  this->_modelMatrix = glm::translate(this->_modelMatrix, translationVector);
}

/**
 * This function is utilized to rotate a drawable object on a specific axis.
 *
 * @param degrees The amount to rotate the object in degrees
 * @param rotationVector The axis to rotate the object on
 */
void DDE::Drawable::rotate(float degrees, glm::vec3 rotationVector) {
  // Rotate the model matrix for the object
  this->_modelMatrix = glm::rotate(this->_modelMatrix, degrees, rotationVector);
}

/**
 * This function is utilized to scale the drawable object in some way on
 * each of it's axis'.
 *
 * @param scaleVector The scale factor for each (x, y, z) component of the
 *                    object
 */
void DDE::Drawable::scale(glm::vec3 scaleVector) {
  // Multiply each scale component by the passed scale vector components.
  this->_scale *= scaleVector;

  // Scale the model matrix for the object
  this->_modelMatrix = glm::scale(this->_modelMatrix, scaleVector);
}
