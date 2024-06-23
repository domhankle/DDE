#pragma once

#include <iostream>
#include <stdlib.h>

namespace DDE {

/**
 * This function is responsible for handling an error in the
 * initialization of GLFW.
 *
 * @param error The error code
 * @param description A description of the error that occured
 */
inline void error_callback(int error, const char *description) {
  std::cerr << "GLFW Error: \nCode: " << error
            << "\nDescription: " << description;
  exit(EXIT_FAILURE);
}

} // namespace DDE
