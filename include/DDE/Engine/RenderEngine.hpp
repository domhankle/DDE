#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderEngine {

  private:
    GLFWwindow* _window;
    void _initializeGLFW();
    void _configureGLFW();
    void _configureWindow();
    void _initializeGLAD();

  public:
    RenderEngine();
    ~RenderEngine();
    void start();
  
};
