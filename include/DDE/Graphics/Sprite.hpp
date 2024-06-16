#pragma once
#include <Glad/glad/glad.h>

namespace DDE {

class Sprite {

private:
  unsigned int _spriteObject;
  // Texture class
  // Position class

public:
  unsigned int getSpriteObject() const;

  Sprite();
  ~Sprite() = default;
};

} // namespace DDE
