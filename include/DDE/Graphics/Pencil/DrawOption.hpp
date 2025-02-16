#pragma once

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
class DrawOption {

public:
  void preDraw() const;
  void postDraw() const;

  ~DrawOption() = default;
  DrawOption() = delete;
};
} // namespace DDE
