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

void drawFunction(DDE::Pencil &pencil, DDE::Quad &triangle) {
  pencil.draw(triangle);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;
  DDE::Quad quad{1.0f, 1.0f};

  DDE::Pencil pencil;
  DDE::Triangle triangle(2.0f, 2.0f, DDE::Vec4{0.3f, 0.8f, 1.0f, 0.1f});
  engine.start(drawFunction, std::ref(pencil), std::ref(quad));

  return 0;
}
