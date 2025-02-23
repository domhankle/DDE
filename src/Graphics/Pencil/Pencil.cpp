#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <cstdarg>

/**
 * This function is used to draw anything that inherits the
 * DDE::Drawable class to the screen. Any DDE::Drawable object
 * must have a "render" function implemented and specify a
 * shader stage to use.
 *
 * @param drawableObject the object to draw to the screen.
 * @param configs The additional draw configurations to utilize.
 */
void DDE::Pencil::draw(DDE::Drawable &drawableObject,
                       DDE::DrawConfigCollection &&configs) const {
  DDE::ShaderEngine::ActivateShaderStage(drawableObject.getShaderPipeline());

  for (const std::unique_ptr<DrawConfig> &config : configs) {
    config->preDraw();
  }

  drawableObject.render();

  for (const std::unique_ptr<DrawConfig> &config : configs) {
    config->postDraw();
  }
}
