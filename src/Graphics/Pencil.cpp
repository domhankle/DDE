#include <DDE/Graphics/Pencil.hpp>

void DDE::Pencil::draw(DDE::Drawable &drawableObject) const {
  DDE::ShaderEngine::ActivateShaderStage(drawableObject.getShaderPipeline());
  drawableObject.render();
}
