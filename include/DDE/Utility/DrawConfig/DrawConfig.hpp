#pragma once

namespace DDE {

/**
 * @class DrawConfig
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

} // namespace DDE
