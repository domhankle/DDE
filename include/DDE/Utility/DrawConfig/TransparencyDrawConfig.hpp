#pragma once

#include <DDE/Utility/DrawConfig/DrawConfig.hpp>

namespace DDE {

/**
 * @class TransparencyDrawConfig
 *
 * This is one of the utility DrawConfig classes that enables
 * transparency on a draw call made on an instance of the
 * Pencil class.
 */
class TransparencyDrawConfig : public DrawConfig {

public:
  void preDraw() const override;
  void postDraw() const override;

  TransparencyDrawConfig() = default;
  ~TransparencyDrawConfig() = default;
};

} // namespace DDE
