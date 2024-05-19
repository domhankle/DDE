#pragma once

#include <iostream>

#include <stdlib.h>
#include <stdio.h>

void error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error: \nCode: " << error << "\nDescription: " << description;
    exit(EXIT_FAILURE);
}
