#include <DDE/Engine/RenderEngine.hpp>
#include <iostream>

void mockDriver() { std::cout << "Hello world!" << std::endl; }

int main() {
  RenderEngine engine;
  engine.setDriver(mockDriver);
  engine.start();
  return 0;
}
