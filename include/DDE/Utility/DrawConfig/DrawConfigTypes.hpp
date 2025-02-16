#pragma once

#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <memory>
#include <vector>

namespace DDE {
// TODO: Documentation
typedef std::unique_ptr<DDE::DrawConfig> DrawConfigEntry;
typedef std::vector<DrawConfigEntry> DrawConfigCollection;

// TODO: Documentation
enum DrawConfigType { TRANSPARENCY = 0 };

} // namespace DDE
