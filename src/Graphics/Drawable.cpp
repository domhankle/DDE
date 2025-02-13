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
    : _shaderPipelineID(shaderPipeline), _color(color) {}

/**
 * This is our function to get the shader pipeline ID from
 * a drawable object in DDE.
 */
DDE::ShaderStage DDE::Drawable::getShaderPipeline() const {
  return this->_shaderPipelineID;
}
