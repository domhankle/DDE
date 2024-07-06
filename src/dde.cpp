#include <Glad/glad/glad.h>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Graphics/Shape.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>

void drawFunction(DDE::ShaderProgram &program, DDE::Triangle &triangle) {
  // Use our shader program
  program.activate();
  triangle.render();
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Shader vertexShader{"../sandbox/shaders/shader.vs.glsl",
                           GL_VERTEX_SHADER};
  DDE::Shader fragmentShader{"../sandbox/shaders/shader.fs.glsl",
                             GL_FRAGMENT_SHADER};

  DDE::ShaderProgram program{{vertexShader, fragmentShader}};

  DDE::Vertex v1{0.0f, 1.0f}, v2{-1.0f, -1.0f}, v3{1.0f, -1.0f};
  DDE::Triangle triangle{v1, v2, v3};

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(program), std::ref(triangle));

  return 0;
}
