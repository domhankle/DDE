#include <DDE/Graphics/Drawable.hpp>

/**
 * The constructor is simply used to specify the shader pipeline
 * used by this drawable object.
 */
DDE::Drawable::Drawable(DDE::ShaderStage shaderPipeline)
    : _shaderPipelineID(shaderPipeline) {}

// TODO: Documentation
DDE::ShaderStage DDE::Drawable::getShaderPipeline() const {
  return this->_shaderPipelineID;
}
