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
  // The camera object that is being used for this Scene
  DDE::Camera _camera;
  // All of the Drawable objects contained within this Scene
  std::vector<std::unique_ptr<DDE::Drawable>> _drawableObjects;

public:
  Scene() = default;
  ~Scene() = default;

  DDE::Camera &getCamera();
  std::vector<std::unique_ptr<DDE::Drawable>> &getDrawableObjects();
  DDE::Drawable &getDrawableObject(unsigned int index);

  void setCamera(const DDE::Camera &camera);

  void addDrawableObject(std::unique_ptr<DDE::Drawable> object);
  void removeDrawableObject(unsigned int index);
};

} // namespace DDE
