#include <DDE/Callbacks.hpp>
#include <DDE/Engine/RenderEngine.hpp>

RenderEngine::RenderEngine() {
  this->_initializeGLFW();
  this->_configureGLFW();
  this->_configureWindow();
}

RenderEngine::~RenderEngine() {
  glfwDestroyWindow(this->_window);
  glfwTerminate();
}

void RenderEngine::_initializeGLFW() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
}

void RenderEngine::_configureGLFW() { glfwSetErrorCallback(error_callback); }

void RenderEngine::_initializeGLAD() {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "GLAD failed to load modern OpenGL extensions\n";
    exit(EXIT_FAILURE);
  }
}

void RenderEngine::_configureWindow() {
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

void RenderEngine::start() {
  while (!glfwWindowShouldClose(this->_window)) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    this->_driver();

    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }
}

void RenderEngine::setDriver(std::function<void()> driver) {
  this->_driver = driver;
}
