#include <DDE/Engine/RenderEngine.hpp>
#include <DDE/Shader/Shader.hpp>
#include <DDE/Shader/ShaderProgram.hpp>
#include <vector>

#include "Glad/glad/glad.h"

// Vertex Array Object
unsigned int vao;

void drawFunction(DDE::ShaderProgram &program) {
  // Use our shader program
  program.use();

  // Bind our VAO holding vertex data
  glBindVertexArray(vao);
  // Draw call to start the render pipeline
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {

  // Create the Render Engine
  DDE::RenderEngine engine;

  DDE::Shader vertexShader{"../sandbox/shaders/shader.vs.glsl",
                           GL_VERTEX_SHADER};
  DDE::Shader fragmentShader{"../sandbox/shaders/shader.fs.glsl",
                             GL_FRAGMENT_SHADER};

  DDE::ShaderProgram program{{vertexShader, fragmentShader}};

  // Create our Vertex Buffer object
  unsigned int vbo;
  glGenBuffers(1, &vbo);

  // Create our Vertex Array object
  glGenVertexArrays(1, &vao);

  // Bind our Vertex Array object to capture the data we configure
  glBindVertexArray(vao);

  // Bind our Array Buffer to the GL_ARRAY_BUFFER target
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  // Our vertices
  std::vector<float> vertices = {-0.75, -0.75, 1.0,  0.75, -0.75,
                                 1.0,   0.0,   0.75, 1.0};

  // Store our data in a location to send to the GPU
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  // Describe our vertices for the GPU
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  // Enable a Vertex Location
  glEnableVertexAttribArray(0);

  // Start the Rendering Enginge
  engine.start(drawFunction, std::ref(program));

  return 0;
}
