#pragma once

#include <iostream>
#include <stdlib.h>

namespace DDE {

inline void error_callback(int error, const char *description) {
  std::cerr << "GLFW Error: \nCode: " << error
            << "\nDescription: " << description;
  exit(EXIT_FAILURE);
}

} // namespace DDE
