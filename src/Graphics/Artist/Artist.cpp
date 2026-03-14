#include "DDE/Engine/ShaderEngine.hpp"
#include <DDE/Graphics/Artist/Artist.hpp>
#include <DDE/Graphics/Drawable.hpp>
#include <iostream>
#include <vector>

void DDE::Artist::drawScene(DDE::Scene &scene) {

  // First retrieve all the Drawable objects on the Scene
  std::vector<std::unique_ptr<DDE::Drawable>> &drawableObjects =
      scene.getDrawableObjects();

  DDE::Camera camera = scene.getCamera();

  for (std::unique_ptr<DDE::Drawable> &drawable : drawableObjects) {
    ShaderEngine::ActivateShaderStage(drawable->getShaderPipeline());
    DDE::ShaderEngine::UpdateViewMatrix(camera.getViewMatrix());
    DDE::ShaderEngine::UpdateProjectionMatrix(camera.getProjectionMatrix());
    this->_pencil.draw(*drawable);
  }
}
