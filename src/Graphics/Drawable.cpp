#include <DDE/Graphics/Drawable.hpp>

/**
 * The constructor is simply used to specify the shader pipeline
 * used by this drawable object.
 */
DDE::Drawable::Drawable(DDE::ShaderStage shaderPipeline)
    : _shaderPipelineID(shaderPipeline) {}
