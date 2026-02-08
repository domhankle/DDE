#include <DDE/Graphics/Drawable.hpp>
#include <DDE/Graphics/Shader/Camera/Camera.hpp>
#include <memory>
#include <vector>
namespace DDE {

/**
 * @class Scene
 *
 * This class defines the container that will hold drawable
 * objects and a camera to view those drawable objects. This
 * class will give mutable access to the Camera and drawable
 * objects.
 */
class Scene {

private:
  DDE::Camera _camera;
  std::vector<std::unique_ptr<DDE::Drawable>> _drawableObjects;

public:
  Scene() = default;
  ~Scene() = default;

  DDE::Camera &getSceneCamera();
  DDE::Drawable &getDrawableObject(unsigned int index);
};

} // namespace DDE
