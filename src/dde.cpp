#include <DDE/Engine/RenderEngine.hpp>
#include <iostream>
#include <vector>

#include "Glad/glad/glad.h"

// Program object
unsigned int program;
// Vertex Array Object
unsigned int vao;

void mockDriver() {
  // Activate our program object
  glUseProgram(program);
  // Bind our VAO holding vertex data
  glBindVertexArray(vao);
  // Draw call to start the render pipeline
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
  // Create the Render Engine
  RenderEngine engine;

  // Create our program object
  program = glCreateProgram();

  // Create our two shader objects
  unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
  unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Vertex Shader source code
  const char* vShaderSource =
      "#version 330\n"
      "layout(location = 0) in vec3 position;\n"
      "void main() {\n"
      " gl_Position = vec4(position, 1.0f);\n"
      "}\n";

  // Fragment Shader source code
  const char* fShaderSource =
      "#version 330\n"
      "out vec4 color;\n"
      "void main() {\n"
      " color = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
      "}\n";

  // Attach shader sources
  glShaderSource(vShader, 1, &vShaderSource, nullptr);
  glShaderSource(fShader, 1, &fShaderSource, nullptr);

  // Compile Shaders
  glCompileShader(vShader);
  glCompileShader(fShader);

  // Status flag
  int success;
  // Error log
  char log[512];

  // Check Vertex Shader compile status
  glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(vShader, 512, nullptr, log);
    std::cerr << "VERTEX SHADER FAILED TO COMPILE!" << std::endl
              << log << std::endl;
    exit(EXIT_FAILURE);
  }

  // Check Fragment Shader compile status
  glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(fShader, 512, nullptr, log);
    std::cerr << "FRAGMENT SHADER FAILED TO COMPILE!" << std::endl
              << log << std::endl;
    exit(EXIT_FAILURE);
  }

  // Attach our shaders to the program object
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);

  // Link our program object
  glLinkProgram(program);

  // Check program link status
  glGetProgramiv(program, GL_LINK_STATUS, &success);

  if (!success) {
    glGetProgramInfoLog(program, 512, nullptr, log);
    std::cerr << "PROGRAM FAILED TO LINK!" << std::endl << log << std::endl;
    exit(EXIT_FAILURE);
  }

  // Clean up our Shader objects
  glDeleteShader(vShader);
  glDeleteShader(fShader);

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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  // Enable a Vertex Location
  glEnableVertexAttribArray(0);

  engine.setDriver(mockDriver);
  engine.start();

  return 0;
}
