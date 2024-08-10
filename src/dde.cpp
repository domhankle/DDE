#include "DDE/Graphics/Shape/Quad.hpp"
#include <Glad/glad/glad.h>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Pencil.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>

void drawFunction(DDE::Pencil &pencil, DDE::Triangle &triange) {
  pencil.draw(triange);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Triangle triangle{2.0f, 2.0f};
  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(triangle));

  return 0;
}
