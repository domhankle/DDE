#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <DDE/Utility/DrawConfig/TransparencyDrawConfig.hpp>

DDE::DrawConfigEntry DDE::GenerateDrawConfig(DDE::DrawConfigType type) {
  return std::make_unique<DDE::TransparencyDrawConfig>();
}
