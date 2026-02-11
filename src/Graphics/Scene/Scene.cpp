#include <DDE/Graphics/Scene/Scene.hpp>

DDE::Camera &DDE::Scene::getCamera() { return this->_camera; }

DDE::Drawable &DDE::Scene::getDrawableObject(unsigned int index) {
  return *this->_drawableObjects.at(index);
}

void DDE::Scene::setCamera(const DDE::Camera &camera) {
  this->_camera = camera;
}

void DDE::Scene::addDrawableObject(std::unique_ptr<DDE::Drawable> object) {
  this->_drawableObjects.push_back(std::move(object));
}

void DDE::Scene::removeDrawableObject(unsigned int index) {
  std::vector<std::unique_ptr<DDE::Drawable>>::iterator position =
      this->_drawableObjects.begin() + index;
  this->_drawableObjects.erase(position);
}
