#pragma once

#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Drawable.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <concepts>
#include <memory>

namespace DDE {
/**
 * @class Pencil
 *
 * This class will handle actually drawing objects to the screen.
 */
class Pencil {

private:
public:
  Pencil() = default;
  ~Pencil() = default;

  /**
   * This function is used to draw anything that inherits the
   * DDE::Drawable class to the screen. Any DDE::Drawable object
   * must have a "render" function implemented and specify a
   * shader stage to use. This function also handles activating any
   * any DrawConfig utility classes.
   *
   * @param Configs Optional template parameter list to specify DrawConfig
   *        classes.
   * @param drawableObject the object to draw to the screen.
   */
  template <typename... Configs>
    requires(std::derived_from<Configs, DDE::DrawConfig> && ...)
  void draw(DDE::Drawable &drawableObject) {

    // Activate the shader stage associated with the drawable object
    DDE::ShaderEngine::ActivateShaderStage(drawableObject.getShaderPipeline());

    // Build a vector of all the draw configs
    std::vector<std::unique_ptr<DDE::DrawConfig>> configs = {};
    (configs.emplace_back(std::make_unique<Configs>()), ...);

    // Call preDraw on all draw configs
    for (const std::unique_ptr<DDE::DrawConfig> &config : configs) {
      config->preDraw();
    }

    // Update the Model Matrix to the drawable object's model matrix
    DDE::ShaderEngine::UpdateModelMatrix(drawableObject.getModelMatrix());
    // Give the default projection matrix
    DDE::ShaderEngine::UpdateProjectionMatrix(
        DDE::Frustum().getProjectionMatrix());

    // Render the drawable object
    drawableObject.render();

    // Call postDraw on all draw configs
    for (const std::unique_ptr<DDE::DrawConfig> &config : configs) {
      config->postDraw();
    }
  }
};

} // namespace DDE
