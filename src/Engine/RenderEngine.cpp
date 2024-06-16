#include <DDE/Callbacks.hpp>
#include <DDE/Engine/RenderEngine.hpp>

DDE::RenderEngine::RenderEngine() {
  this->_initializeGLFW();
  this->_configureGLFW();
  this->_configureWindow();
}

DDE::RenderEngine::~RenderEngine() {
  glfwDestroyWindow(this->_window);
  glfwTerminate();
}

void DDE::RenderEngine::_initializeGLFW() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
}

void DDE::RenderEngine::_configureGLFW() {
  glfwSetErrorCallback(DDE::error_callback);
}

void DDE::RenderEngine::_initializeGLAD() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "GLAD failed to load modern OpenGL extensions\n";
    exit(EXIT_FAILURE);
  }
}

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
