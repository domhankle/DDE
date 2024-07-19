#include <Glad/glad/glad.h>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Pencil.hpp>
#include <DDE/Graphics/Shape/Triangle.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>

void drawFunction(DDE::Pencil &pencil, DDE::Triangle &triangle) {
  pencil.draw(triangle);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Vertex v1{0.0f, 1.0f}, v2{-1.0f, -1.0f}, v3{1.0f, -1.0f};
  DDE::Triangle triangle{v1, v2, v3};
  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(triangle));

  return 0;
}
