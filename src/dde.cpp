#include "DDE/Graphics/Drawable.hpp"
#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Artist/Artist.hpp>
#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Graphics/Shader/Camera/Camera.hpp>
#include <DDE/Graphics/Shader/Shader.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <DDE/Utility/DrawConfig/TransparencyDrawConfig.hpp>
#include <DDE/Utility/PositionTypes.hpp>
#include <Glad/glad/glad.h>
#include <functional>
#include <glm/fwd.hpp>
#include <memory>
#include <vector>

// Base translation vector
glm::vec3 translation(1.0f, 0.0f, 0.0f);

// Our degree of rotation per transformation
const float rotationDegrees = 0.01f;

// Base scale vector
glm::vec3 scale(1.01f, 1.01f, 0.0f);

// Helper function for translating a quad
void translateQuad(DDE::Drawable &quad) {
  quad.translate(translation);
  if (quad.getPosition().x >= 100.0f || quad.getPosition().x <= -100.0f) {
    translation.x *= -1;
  }
}

// Helper function for rotating a quad
void rotateQuad(DDE::Drawable &quad) {
  quad.rotate(rotationDegrees, DDE::Z_AXIS_VECTOR);
}

// Helper function for scaling a quad
void scaleQuad(DDE::Drawable &quad) {
  quad.scale(scale);
  if (quad.getScale().x >= 2.0f) {
    scale.x = 0.99f;
    scale.y = 0.99f;
  } else if (quad.getScale().x <= 0.5f) {
    scale.x = 1.01f;
    scale.y = 1.01f;
  }
}

// Our render function
void drawFunction(DDE::Artist &artist, DDE::Scene &scene) {

  // Translate the first quad back and forth
  translateQuad(scene.getDrawableObject(0));

  // Rotate the second quad on the Z-Axis
  rotateQuad(scene.getDrawableObject(1));

  // Scale the third quad to double it's size then back down to half it's size
  // over and over
  scaleQuad(scene.getDrawableObject(2));

  artist.drawScene(scene);
}

// Helper function to generate our Quad shapes
std::vector<std::unique_ptr<DDE::Drawable>> getQuads() {
  std::vector<std::unique_ptr<DDE::Drawable>> toReturn;

  std::unique_ptr<DDE::Drawable> quad1 =
      std::make_unique<DDE::Quad>(25.0, 25.0f);
  quad1->translate(glm::vec3(0, 50.0f, 0));

  std::unique_ptr<DDE::Drawable> quad2 =
      std::make_unique<DDE::Quad>(25.0f, 25.0f);

  std::unique_ptr<DDE::Drawable> quad3 =
      std::make_unique<DDE::Quad>(25.0f, 25.0f);
  quad3->translate(glm::vec3(0, -50.0f, 0));

  toReturn.push_back(std::move(quad1));
  toReturn.push_back(std::move(quad2));
  toReturn.push_back(std::move(quad3));

  return toReturn;
}

// Helper function to retrieve a Scene
DDE::Scene getScene() {
  DDE::Scene toReturn;

  auto drawables = getQuads();

  for (std::unique_ptr<DDE::Drawable> &drawable : drawables) {
    toReturn.addDrawableObject(std::move(drawable));
  }

  toReturn.setCamera(DDE::Camera());

  return toReturn;
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;
  // Create our Scene
  DDE::Scene scene = getScene();
  // Create artist
  DDE::Artist artist;

  engine.start(drawFunction, std::ref(artist), std::ref(scene));

  return 0;
}
