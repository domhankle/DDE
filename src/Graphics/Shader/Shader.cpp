#include <Glad/glad/glad.h>

#include <DDE/Graphics/Shader/Shader.hpp>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

/**
 * Getter for the shader source code
 *
 * @returns the source code associated with this shader as a string
 */
std::string DDE::Shader::getSourceCode() const { return this->_sourceCode; }

/**
 * Getter fot the shader type
 *
 * @returns the type of OpenGL shader this is as a GLenum
 */
unsigned int DDE::Shader::getType() const { return this->_type; }

/**
 * Getter for the OpenGL object ID
 *
 * @returns the underlying OpenGL shader object ID
 */
unsigned int DDE::Shader::getShaderObject() const {
  return this->_shaderObject;
}

/**
 * Specifies whether the shader was compiled on construction or not
 *
 * @returns True - This shader was compiled on construction
 *          False - This shader was NOT compiled on construction
 */
bool DDE::Shader::isAutoCompiled() const { return this->_autoCompile; }

/**
 * This is the first constructor for the Shader object that
 * takes the file path of the source code as a string by reference
 *
 * @param filePath The path to the file holding the Shader source code
 * @param shaderType The OpenGL shader type of this Shader object
 */
DDE::Shader::Shader(std::string &filePath, unsigned int shaderType,
                    bool autoCompile)
    : _type{shaderType}, _autoCompile(autoCompile) {
  try {
    this->_sourceCode = this->_extractShaderSource(filePath);

    // Compile shader if it is configured to compile on construction
    if (this->_autoCompile) {
      this->_compileShaderObject(this->_sourceCode.c_str(), shaderType);
    }
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * This is the second constructor for the Shader object that
 * takes the file path of the source code as a string rvalue
 *
 * @param filePath The path to the file holding the Shader source code
 * @param shaderType The OpenGL shader type of this Shader object
 */
DDE::Shader::Shader(std::string &&filePath, unsigned int shaderType,
                    bool autoCompile)
    : _type{shaderType}, _autoCompile(autoCompile) {
  try {
    this->_sourceCode = this->_extractShaderSource(filePath);

    // Compile shader if it is configured to compile on construction
    if (this->_autoCompile) {
      this->_compileShaderObject(this->_sourceCode.c_str(), shaderType);
    }
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * This function is a public entry point to compile a Shader object.
 * It is necessary whenever a Shader object is created and configured
 * to not compile on construction.
 *
 * @param filePath The path to the file holding the Shader source code
 */
void DDE::Shader::compileShader(std::string &filePath) {
  try {
    this->_sourceCode = this->_extractShaderSource(filePath);
    this->_compileShaderObject(this->_sourceCode.c_str(), this->_type);
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * Setter for the source code of a Shader object
 *
 * @param filePath The path to the file holding the Shader source code
 */
void DDE::Shader::setSourceCode(std::string &filePath) {
  this->_sourceCode = this->_extractShaderSource(filePath);
}

/**
 * This function is used to actually extract the Shader Source code from
 * a file and store it into a std::string variable.
 *
 * @param filePath The path to the file holding the Shader source code
 */
std::string DDE::Shader::_extractShaderSource(std::string &filePath) const {
  std::ifstream shaderSourceFile(filePath);

  // If we are unable to open the file, throw a runtime exception
  if (!shaderSourceFile.is_open()) {
    std::stringstream ssError;
    ssError << "Could not open file " << filePath << "\n";
    throw std::runtime_error(ssError.str());
  }

  std::string toReturn =
      std::string(std::istreambuf_iterator<char>(shaderSourceFile),
                  std::istreambuf_iterator<char>());

  shaderSourceFile.close();

  return toReturn;
}

/**
 * This function is used to check whether or not the Shader object
 * successfully compiled.
 *
 * @param shaderObject The underlying OpenGL shader object ID
 */
bool DDE::Shader::_shaderCompiledSuccessfully(unsigned int shaderObject) const {
  int successfulCompilation;

  glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &successfulCompilation);

  return successfulCompilation;
}

/**
 * This function handles actually creating and compiling
 * the underlying OpenGL shader object abstracted by the
 * Shader class.
 *
 * @param sourceCode A const char* holding the source code for the shader.
 * @param type The OpenGL type of Shader this object abstracts
 */
void DDE::Shader::_compileShaderObject(const char *sourceCode,
                                       unsigned int type) {
  // Create the OpenGL shader object
  this->_shaderObject = glCreateShader(type);

  // Attach the source code to the OpenGL shader object
  glShaderSource(this->_shaderObject, 1, &sourceCode, nullptr);

  // Attempt to compile the OpenGL shader
  glCompileShader(this->_shaderObject);

  // This if block is hit if the Shader failed to compile
  if (!this->_shaderCompiledSuccessfully(this->_shaderObject)) {
    // Get Shader info log
    char compilationLog[512];
    glGetShaderInfoLog(this->_shaderObject, 512, nullptr, compilationLog);

    // Construct a proper error message
    std::stringstream ssError;
    ssError << "Failed to compile shader object!\n"
            << "Shader Object ID: " << this->_shaderObject << "\n"
            << "Shader Type: " << this->_type << "\n"
            << "Shader Source:\n\n"
            << this->_sourceCode << "\n\n"
            << "OpenGL Info Log:\n\n"
            << compilationLog << "\n";

    // Throw runtime exception
    throw std::runtime_error(ssError.str());
  }
}
