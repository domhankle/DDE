#include <DDE/Utility/DrawConfig/TransparencyDrawConfig.hpp>
#include <Glad/glad/glad.h>

/**
 * This function handles enabling GL_BLEND and
 * configuring the correct glBlendFunc parameters.
 *
 * https://stackoverflow.com/questions/1617370/how-to-use-alpha-transparency-in-opengl
 * https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBlendFunc.xhtml
 */
void DDE::TransparencyDrawConfig::preDraw() const {
  // Enable blending
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDepthMask(GL_FALSE);
}

/**
 * This function is utilized to disable blending after
 * transparent rendering is complete.
 */
void DDE::TransparencyDrawConfig::postDraw() const {
  // Disable blending
  glDepthMask(GL_TRUE);
  glDisable(GL_BLEND);
}
