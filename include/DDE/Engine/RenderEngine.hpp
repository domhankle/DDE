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

public:
  RenderEngine();
  ~RenderEngine();

  template <typename F, typename... Args>
    requires std::invocable<F, Args...>
  void start(F drawFunction, Args... drawFunctionParameters) {

    while (!glfwWindowShouldClose(this->_window)) {
      glClearColor(0.0, 0.0, 0.0, 0.0);
      glClear(GL_COLOR_BUFFER_BIT);

      drawFunction(drawFunctionParameters...);

      glfwSwapBuffers(this->_window);
      glfwPollEvents();
    }
  }
};
