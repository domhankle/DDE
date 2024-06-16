#include <DDE/Shader/Shader.hpp>
#include <Glad/glad/glad.h>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>

std::string Shader::getSourceCode() const { return this->_sourceCode; }

unsigned int Shader::getType() const { return this->_type; }

unsigned int Shader::getShaderObject() const { return this->_shaderObject; }

bool Shader::isAutoCompiled() const { return this->_autoCompile; }

Shader::Shader(std::string &filePath, unsigned int shaderType, bool autoCompile)
    : _type{shaderType}, _autoCompile(autoCompile) {

  try {
    this->_sourceCode = this->_extractShaderSource(filePath);
    if (this->_autoCompile) {
      this->_compileShaderObject(this->_sourceCode.c_str(), shaderType);
    }
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

Shader::Shader(std::string &&filePath, unsigned int shaderType,
               bool autoCompile)
    : _type{shaderType}, _autoCompile(autoCompile) {

  try {
    this->_sourceCode = this->_extractShaderSource(filePath);
    if (this->_autoCompile) {
      this->_compileShaderObject(this->_sourceCode.c_str(), shaderType);
    }
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Shader::compileShader(std::string &filePath) {
  try {
    this->_sourceCode = this->_extractShaderSource(filePath);
    this->_compileShaderObject(this->_sourceCode.c_str(), this->_type);
  } catch (const std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Shader::setSourceCode(std::string &filePath) {
  this->_sourceCode = this->_extractShaderSource(filePath);
}

std::string Shader::_extractShaderSource(std::string &filePath) const {
  std::ifstream shaderSourceFile(filePath);

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

bool Shader::_shaderCompiledSuccessfully(unsigned int shaderObject) const {

  int successfulCompilation;

  glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &successfulCompilation);

  return successfulCompilation;
}

void Shader::_compileShaderObject(const char *sourceCode, unsigned int type) {
  this->_shaderObject = glCreateShader(type);

  glShaderSource(this->_shaderObject, 1, &sourceCode, nullptr);
  glCompileShader(this->_shaderObject);

  if (!this->_shaderCompiledSuccessfully(this->_shaderObject)) {

    char compilationLog[512];
    glGetShaderInfoLog(this->_shaderObject, 512, nullptr, compilationLog);

    std::stringstream ssError;
    ssError << "Failed to compile shader object!\n"
            << "Shader Object ID: " << this->_shaderObject << "\n"
            << "Shader Type: " << this->_type << "\n"
            << "Shader Source:\n\n"
            << this->_sourceCode << "\n\n"
            << "OpenGL Info Log:\n\n"
            << compilationLog << "\n";

    throw std::runtime_error(ssError.str());
  }
}
