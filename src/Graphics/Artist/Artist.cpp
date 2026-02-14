#include <DDE/Graphics/Artist/Artist.hpp>
#include <DDE/Graphics/Drawable.hpp>
#include <vector>

void DDE::Artist::drawScene(DDE::Scene &scene) {

  // First retrieve all the Drawable objects on the Scene
  std::vector<std::unique_ptr<DDE::Drawable>> &drawableObjects =
      scene.getDrawableObjects();
}
