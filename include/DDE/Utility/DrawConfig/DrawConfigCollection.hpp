#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <concepts>
#include <memory>
#include <vector>

namespace DDE {

// TODO: Documentation
class DrawConfigCollection {

public:
  using DrawConfigEntry = std::unique_ptr<DDE::DrawConfig>;
  using DrawConfigCollectionIterator = std::vector<DrawConfigEntry>::iterator;
  using ConstDrawConfigCollectionIterator =
      std::vector<DrawConfigEntry>::const_iterator;

private:
  std::vector<DrawConfigEntry> _configs;

public:
  DrawConfigCollectionIterator begin();
  DrawConfigCollectionIterator end();
  ConstDrawConfigCollectionIterator begin() const;
  ConstDrawConfigCollectionIterator end() const;

  // TODO: Documentation
  template <typename ConfigType>
    requires std::derived_from<ConfigType, DDE::DrawConfig>
  void addConfig() {
    this->_configs.push_back(std::make_unique<ConfigType>());
  }
};

} // namespace DDE
