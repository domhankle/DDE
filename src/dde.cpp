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

void drawFunction(DDE::Pencil &pencil, DDE::Quad &square) {
  pencil.draw(square);
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Vertex v1{-0.10f, -0.32f}, v2{0.75f, 0.33f}, v3{0.75f, -0.35f},
      v4{-0.2f, 0.35f};

  DDE::Quad square{v1, v2, v3, v4};
  DDE::Pencil pencil;

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(pencil), std::ref(square));

  return 0;
}
