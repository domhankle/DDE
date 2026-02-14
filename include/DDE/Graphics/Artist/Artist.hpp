#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Graphics/Scene/Scene.hpp>

namespace DDE {

// TODO: Documentation
class Artist {

private:
  DDE::Pencil _pencil;

public:
  void drawScene(DDE::Scene &scene);

  Artist() = default;
  ~Artist() = default;
};

} // namespace DDE
