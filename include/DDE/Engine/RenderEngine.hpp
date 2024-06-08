#pragma once
#include <functional>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Glad/glad/glad.h>

class RenderEngine {
private:
  GLFWwindow *_window;
  void _initializeGLFW();
  void _configureGLFW();
  void _configureWindow();
  void _initializeGLAD();
  std::function<void()> _driver;

public:
  RenderEngine();
  ~RenderEngine();
  void start();
  void setDriver(std::function<void()> driver);
};
