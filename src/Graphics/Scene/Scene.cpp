#include <DDE/Graphics/Scene/Scene.hpp>

/**
 * This getter provides a reference to the Scene's camera
 *
 * @returns A reference to the Scene camera
 */
DDE::Camera &DDE::Scene::getCamera() { return this->_camera; }

/**
 * This getter is used to retrieve one of the drawable objects
 * inside of the Scene.
 *
 * @param index The index ID of the drawable object to retrieve
 *
 * @returns A reference to the drawable object inside the Scene
 *          with the same specified index ID
 */
DDE::Drawable &DDE::Scene::getDrawableObject(unsigned int index) {
  return *this->_drawableObjects.at(index);
}

/**
 * This setter is used to configure the camera associated with
 * this Scene.
 *
 * @param camera The camera to configure the Scene to use
 */
void DDE::Scene::setCamera(const DDE::Camera &camera) {
  this->_camera = camera;
}

/**
 * Add a drawable object to the Scene
 *
 * @param object The drawable object to add to the Scene.
 */
void DDE::Scene::addDrawableObject(std::unique_ptr<DDE::Drawable> object) {
  this->_drawableObjects.push_back(std::move(object));
}

/**
 * Remove a drawable object from the Scene
 *
 * @param index The index ID of the drawable object to remove from
 *              the scene.
 */
void DDE::Scene::removeDrawableObject(unsigned int index) {
  std::vector<std::unique_ptr<DDE::Drawable>>::iterator position =
      this->_drawableObjects.begin() + index;
  this->_drawableObjects.erase(position);
}
