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

void drawFunction(DDE::Pencil &pencil, DDE::Quad &square,
                  DDE::Triangle &triange) {
  pencil.draw(square);
  pencil.draw(triange);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Vertex v1{0.0f, 0.5f}, v3{0.5f, 0.0f}, v4{-0.5f, 0.0f}, v2{0.0f, -0.5f};
  DDE::Quad square{v1, v2, v3, v4};

  DDE::Vertex v5{-1.0f, 1.0f}, v6{0.0f, 1.0f}, v7{-0.5, 0.5};
  DDE::Triangle triangle{v5, v6, v7};
  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(square),
               std::ref(triangle));

  return 0;
}
