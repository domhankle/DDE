#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
namespace DDE {

// TODO: Documentation
class TransparencyDrawConfig : DrawConfig {

public:
  void preDraw() const override;
  void postDraw() const override;
};

} // namespace DDE
