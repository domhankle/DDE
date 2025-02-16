#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <cstdarg>
#include <initializer_list>

/**
 * This function is used to draw anything that inherits the
 * DDE::Drawable class to the screen. Any DDE::Drawable object
 * must have a "render" function implemented and specify a
 * shader stage to use.
 *
 * @param drawableObject the object to draw to the screen.
 */
void DDE::Pencil::draw(DDE::Drawable &drawableObject,
                       std::initializer_list<DDE::DrawConfig *> configs) const {
  DDE::ShaderEngine::ActivateShaderStage(drawableObject.getShaderPipeline());

  for (DDE::DrawConfig *config : configs) {
    config->preDraw();
  }

  drawableObject.render();

  for (DDE::DrawConfig *config : configs) {
    config->postDraw();
  }
}
