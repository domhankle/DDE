#include <DDE/Callbacks.hpp>
#include <DDE/Engine/RenderEngine.hpp>

/**
 * This is the default and only constructor for a
 * RenderEngine object. This class is not meant to be complicated
 * and is just a way to configure the render loop.
 */
DDE::RenderEngine::RenderEngine() {
  this->_initializeGLFW();
  this->_configureGLFW();
  this->_configureWindow();
}

/**
 * This is the destructor for the RenderEngine and
 * handles cleaning up GLFW.
 */
DDE::RenderEngine::~RenderEngine() {
  glfwDestroyWindow(this->_window);
  glfwTerminate();
}

/**
 * This function handles initializing GLFW and terminates
 * the program if it fails
 */
void DDE::RenderEngine::_initializeGLFW() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
}

/**
 * This function handles configuring the callback
 * functions for GLFW.
 */
void DDE::RenderEngine::_configureGLFW() {
  glfwSetErrorCallback(DDE::error_callback);
}

/**
 * This function handles intializing GLAD and terminates
 * the program if it fails
 */
void DDE::RenderEngine::_initializeGLAD() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "GLAD failed to load modern OpenGL extensions\n";
    exit(EXIT_FAILURE);
  }
}

/**
 * This function handles configuring the GLFW window
 * and actually opening it.
 *
 * TODO: Make the GLFW settings configurable for the programmer
 */
void DDE::RenderEngine::_configureWindow() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  this->_window = glfwCreateWindow(500, 500, "DDE Window", nullptr, nullptr);
  if (!this->_window) {
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(this->_window);
  this->_initializeGLAD();
  glfwSwapInterval(1);
}
