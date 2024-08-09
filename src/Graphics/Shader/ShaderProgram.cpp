#include <DDE/Graphics/Shader/ShaderProgram.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>

/**
 * To construct a ShaderProgram, an initializer list of Shader objects
 * is required to specify which shader objects to link together.
 *
 * @param shaders The list of shaders to link together.
 */
DDE::ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaders)
    : _shaderSources{shaders} {

  try {
    this->_linkProgram(this->_shaderSources);
  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
    exit(EXIT_FAILURE);
  }
}

/**
 * Getter to retrieve all Shader objects associated with this program.
 *
 * @returns The shader objects associated with this program.
 */
std::vector<DDE::Shader> DDE::ShaderProgram::getShaderSources() const {
  return this->_shaderSources;
}

/**
 * Getter to retrieve the OpenGL ID of the internal OpenGL program
 * object on this ShaderProgram object.
 *
 * @returns the internal OpenGL program object ID.
 */
unsigned int DDE::ShaderProgram::getProgramObject() const {
  return this->_programObject;
}

/**
 * Used to determine if a the internal OpenGL program object
 * successfully linked all of the Shader objects on this
 * ShaderProgram object.
 *
 * @returns True - OpenGL successfully linked the Shader objects
 *          False - OpenGL failed to link the Shader objects
 */
bool DDE::ShaderProgram::_programLinkedSuccessfully(
    unsigned int programObject) const {
  int successfulLinking;

  glGetProgramiv(programObject, GL_LINK_STATUS, &successfulLinking);

  return successfulLinking;
}

/**
 * Used to tell OpenGL to use the internal OpenGL program object
 * on this ShaderProgram object for rendering.
 */
void DDE::ShaderProgram::activate() const {
  glUseProgram(this->_programObject);
}

/**
 * This function is used to actually execute the OpenGL
 * functionality of linking together OpenGL shader objects.
 *
 * @param sources The vector of abstracted OpenGL Shader objects
 */
void DDE::ShaderProgram::_linkProgram(std::vector<Shader> &sources) {

  // Create an OpenGL program object
  this->_programObject = glCreateProgram();

  // Attach all OpenGL shader objects to our program object
  for (const Shader &source : sources) {
    glAttachShader(this->_programObject, source.getShaderObject());
  }

  // Tell OpenGL to attempt to link the shader objects
  glLinkProgram(this->_programObject);

  // This if block is used for error handling when the program object fails to
  // link
  if (!this->_programLinkedSuccessfully(this->_programObject)) {

    // Get OpenGL linking info log
    char linkingLog[512];
    glGetProgramInfoLog(this->_programObject, 512, nullptr, linkingLog);

    // Prepare an error output
    std::stringstream ssError;
    ssError << "Failed to link shader program!\n"
            << "Shader Program Object ID: " << this->_programObject << "\n"
            << "Shader Object IDs:\n\n";

    for (const Shader &shader : sources) {
      ssError << shader.getShaderObject() << "\n";
    }
    ssError << "\nOpenGL Info Log:\n\n" << linkingLog << "\n";

    // Throw a runtime error
    throw std::runtime_error(ssError.str());
  }
  // If we reach this else block, the program linked successfully
  else {

    // Clean up all of our OpenGL shader objects
    for (const Shader &shader : sources) {
      glDeleteShader(shader.getShaderObject());
    }
  }
}
