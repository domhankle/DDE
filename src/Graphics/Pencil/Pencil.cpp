#include <DDE/Graphics/Pencil.hpp>

/**
 * This function is used to draw anything that inherits the
 * DDE::Drawable class to the screen. Any DDE::Drawable object
 * must have a "render" function implemented and specify a
 * shader stage to use.
 *
 * @param drawableObject the object to draw to the screen.
 */
void DDE::Pencil::draw(DDE::Drawable &drawableObject) const {
  DDE::ShaderEngine::ActivateShaderStage(drawableObject.getShaderPipeline());

  // TODO: Decide where we want to actually do this
  glDepthMask(GL_FALSE);
  drawableObject.render();
  glDepthMask(GL_TRUE);
}
