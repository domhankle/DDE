#pragma once

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
  void draw(DDE::Drawable &drawableObject);

  /**
   *
   * TODO: Update all this documentaiton
   *
   * This function is used to draw anything that inherits the
   * DDE::Drawable class to the screen. Any DDE::Drawable object
   * must have a "render" function implemented and specify a
   * shader stage to use.
   *
   * @param drawableObject the object to draw to the screen.
   * @param configs The additional draw configurations to utilize.
   */
  template <typename... Configs>
    requires(std::derived_from<Configs, DDE::DrawConfig> && ...)
  void draw(DDE::Drawable &drawableObject) const {

    std::vector<std::unique_ptr<DDE::DrawConfig>> configs = {};
    (configs.emplace_back(std::make_unique<Configs>()), ...);

    for (const auto &config : configs) {
      config->preDraw();
    }

    drawableObject.render();

    for (const auto &config : configs) {
      config->postDraw();
    }
  }
};

} // namespace DDE
