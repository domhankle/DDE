#pragma once

#include <DDE/Graphics/Drawable.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
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
  void draw(DDE::Drawable &drawableObject,
            std::vector<std::unique_ptr<DDE::DrawConfig>> = {}) const;

  Pencil() = default;
  ~Pencil() = default;
};

} // namespace DDE
