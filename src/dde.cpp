#include <DDE/Graphics/Shape/Quad.hpp>
#include <Glad/glad/glad.h>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Pencil.hpp>
#include <DDE/Graphics/Shader/Shader.hpp>
#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>

void drawFunction(DDE::Pencil &pencil, DDE::Triangle &triangle) {
  pencil.draw(triangle);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Triangle triangle{2.0, 2.0};

  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(triangle));

  return 0;
}
