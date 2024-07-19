#pragma once

#include "DDE/Graphics/Drawable.hpp"
namespace DDE {

class Pencil {

private:
public:
  void draw(DDE::Drawable &drawableObject) const;

  Pencil() = default;
  ~Pencil() = default;
};

} // namespace DDE
