#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>

#include "DDE/Graphics/Shape.hpp"
#include "Glad/glad/glad.h"

void drawFunction(DDE::ShaderProgram &program,
                  std::vector<DDE::Triangle> &triangles) {
  // Use our shader program
  program.use();

  // Draw our triangles
  for (DDE::Triangle &triangle : triangles) {
    triangle.render();
  }
}

int main() {

  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Shader vertexShader{"../sandbox/shaders/shader.vs.glsl",
                           GL_VERTEX_SHADER};
  DDE::Shader fragmentShader{"../sandbox/shaders/shader.fs.glsl",
                             GL_FRAGMENT_SHADER};

  DDE::ShaderProgram program{{vertexShader, fragmentShader}};

  // Triangle one
  DDE::Vertex leftVertex = DDE::Vertex(-0.75, -0.75, 1.0);
  DDE::Vertex rightVertex = DDE::Vertex(0.75, -0.75, 1.0);
  DDE::Vertex topVertex = DDE::Vertex(-0.75, 0.75, 1.0);
  DDE::Triangle triangle(leftVertex, rightVertex, topVertex);

  // Triangle two
  leftVertex = DDE::Vertex(0.75, 0.75, 1.0);
  rightVertex = DDE::Vertex(0.75, -0.75, 1.0);
  topVertex = DDE::Vertex(-0.75, 0.75, 1.0);
  DDE::Triangle triangle2(leftVertex, rightVertex, topVertex);

  // Package our triangles
  std::vector<DDE::Triangle> triangles{triangle, triangle2};

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(program), std::ref(triangles));

  return 0;
}
