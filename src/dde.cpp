#include <Glad/glad/glad.h>

#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Graphics/Shape.hpp>
#include <DDE/Graphics/Sprite.hpp>
#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>

void drawFunction(DDE::ShaderProgram &program, DDE::Sprite &sprite) {
  // Use our shader program
  program.activate();
  sprite.render();
}

int main() {
  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Shader vertexShader{"../sandbox/shaders/shader.vs.glsl",
                           GL_VERTEX_SHADER};
  DDE::Shader fragmentShader{"../sandbox/shaders/shader.fs.glsl",
                             GL_FRAGMENT_SHADER};

  DDE::ShaderProgram program{{vertexShader, fragmentShader}};

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(program), std::ref(mySprite));

  return 0;
}
