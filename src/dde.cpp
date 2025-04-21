#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <Glad/glad/glad.h>
#include <glm/fwd.hpp>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Graphics/Shader/Shader.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Utility/DrawConfig/TransparencyDrawConfig.hpp>
#include <functional>
#include <vector>

// Base translation vector
glm::vec3 translation(0.01f, 0.0f, 0.0f);

// Vector representing our rotation axis
glm::vec3 rotationAxis(0.0f, 0.0f, 1.0f);
// Our degree of rotation per transformation
const float rotationDegrees = 0.01f;

// Base scale vector
glm::vec3 scale(1.01f, 1.01f, 0.0f);

// Helper function for translating a quad
void translateQuad(DDE::Quad &quad) {
  quad.translate(translation);
  if (quad.getPosition().x >= 1.0f || quad.getPosition().x <= -1.0f) {
    translation.x *= -1;
  }
}

// Helper function for rotating a quad
void rotateQuad(DDE::Quad &quad) { quad.rotate(rotationDegrees, rotationAxis); }

// Helper function for scaling a quad
void scaleQuad(DDE::Quad &quad) {
  quad.scale(scale);
  if (quad.getSize().x >= 2.0f) {
    scale.x = 0.99f;
    scale.y = 0.99f;
  } else if (quad.getSize().x <= 0.5f) {
    scale.x = 1.01f;
    scale.y = 1.01f;
  }
}

// Our render function
void drawFunction(DDE::Pencil &pencil, std::vector<DDE::Quad> &quads) {

  // Translate the first quad back and forth
  translateQuad(quads[0]);

  // Rotate the second quad on the Z-Axis
  rotateQuad(quads[1]);

  // Scale the third quad to double it's size then back down to half it's size
  // over and over
  scaleQuad(quads[2]);

  // Draw each quad at the end of each transformation
  for (DDE::Quad quad : quads) {
    pencil.draw(quad);
  }
}

// Helper function to generate our Quad shapes
std::vector<DDE::Quad> getQuads() {

  DDE::Quad quad1{0.25f, 0.25f};
  quad1.translate(glm::vec3(0, 0.5f, 0));

  DDE::Quad quad2{0.25f, 0.25f};

  DDE::Quad quad3{0.25f, 0.25f};
  quad3.translate(glm::vec3(0, -0.5f, 0));

  return std::vector<DDE::Quad>{quad1, quad2, quad3};
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  // Get our list of Quads
  std::vector<DDE::Quad> quads = getQuads();

  // Get our Pencil
  DDE::Pencil pencil;

  // Start the render loop with our render function
  engine.start(drawFunction, std::ref(pencil), std::ref(quads));

  return 0;
}
