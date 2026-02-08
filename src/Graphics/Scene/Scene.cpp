#include <DDE/Graphics/Scene/Scene.hpp>

DDE::Camera &DDE::Scene::getSceneCamera() { return this->_camera; }

DDE::Drawable &DDE::Scene::getDrawableObject(unsigned int index) {
  return *this->_drawableObjects.at(index);
}
