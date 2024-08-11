#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Pencil.hpp>
#include <DDE/Graphics/Shape/Quad.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>
#include <Glad/glad/glad.h>

void drawFunction(DDE::Pencil &pencil, DDE::Quad &square) {
  pencil.draw(square);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Quad square{2.0, 2.0};

  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(square));

  return 0;
}
