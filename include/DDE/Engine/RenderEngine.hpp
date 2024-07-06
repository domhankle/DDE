#pragma once
#include <functional>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Glad/glad/glad.h>

namespace DDE {

/**
 * @class RenderEngine
 *
 * This class is used to abstract the process of initailizing
 * a GLFW window and GLAD to utilize modern OpenGL functions.
 * It also abstracts the render loop from the programmer, and they
 * just need to worry about making a function that handles the drawing.
 */
class RenderEngine {
private:
  // GLFW window
  GLFWwindow *_window;

  void _initializeGLFW();
  void _configureGLFW();
  void _configureWindow();
  void _initializeGLAD();

public:
  RenderEngine();
  ~RenderEngine();

  /**
   * This is a template function that mimics a render loop
   * for a typical graphics program. It allows the programmer
   * to actually pass in the abstracted function they want to be ran
   * every frame. Some basic OpenGL and GLFW calls are made to handle
   * clearing the window, but drawFunction is completely unique to
   * the caller.
   *
   * @param drawFunction The address to the function that will run every frame.
   * @param ...Args All of the individual parameters for drawFunction
   *
   * @usage
   *
   * auto myFunction = [](int x, int y){ std::cout << "Drawing " << x + y <<
   * std::endl; };
   *
   * DDE::RenderEngine engine;
   * engine.start(myFunction, 5, 10);
   *
   */
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

} // namespace DDE
