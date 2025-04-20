#include "glm/fwd.hpp"
#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <Glad/glad/glad.h>

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

void drawFunction(DDE::Pencil &pencil, DDE::Quad &quad) {
  pencil.draw(quad);
  quad.rotate(1.0, glm::vec3(0.0, 0.0, 1.0));
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;
  DDE::Quad quad{1.0f, 1.0f};

  DDE::Pencil pencil;
  engine.start(drawFunction, std::ref(pencil), std::ref(quad));

  return 0;
}
