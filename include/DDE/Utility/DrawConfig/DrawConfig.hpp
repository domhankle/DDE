#pragma once

#include <DDE/Utility/DrawConfig/DrawConfigTypes.hpp>
#include <memory>
#include <vector>

namespace DDE {

/**
 * @class DrawOption
 *
 * This class defines the shape of an object
 * that is used to specify two functions:
 *
 * 1. A pre-draw option that runs before rendering on the Pencil class
 * 2. A post-draw option that runs after rendering on the Pencil class
 */
class DrawConfig {

public:
  virtual void preDraw() const = 0;
  virtual void postDraw() const = 0;

  ~DrawConfig() = default;
  DrawConfig() = default;
};

DDE::DrawConfigEntry GenerateDrawConfig(DDE::DrawConfigType type);

} // namespace DDE
