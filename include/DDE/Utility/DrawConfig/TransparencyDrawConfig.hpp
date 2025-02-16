#pragma once

#include <DDE/Utility/DrawConfig/DrawConfig.hpp>

namespace DDE {

// TODO: Documentation
class TransparencyDrawConfig : public DrawConfig {

public:
  void preDraw() const override;
  void postDraw() const override;

  TransparencyDrawConfig() = default;
  ~TransparencyDrawConfig() = default;
};

} // namespace DDE
