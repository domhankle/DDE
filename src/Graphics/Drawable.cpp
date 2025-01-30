#include <DDE/Graphics/Drawable.hpp>

/**
 * The constructor is simply used to specify the shader pipeline
 * used by this drawable object.
 */
DDE::Drawable::Drawable(DDE::ShaderStage shaderPipeline)
    : _shaderPipelineID(shaderPipeline) {}

/**
 * This is our function to get the shader pipeline ID from
 * a drawable object in DDE.
 */
DDE::ShaderStage DDE::Drawable::getShaderPipeline() const {
  return this->_shaderPipelineID;
}
