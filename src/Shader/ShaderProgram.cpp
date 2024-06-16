#include <DDE/Shader/ShaderProgram.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>

DDE::ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaders)
    : _shaderSources{shaders} {
  try {
    this->_linkProgram(this->_shaderSources);
  } catch (std::exception &exception) {
    std::cerr << "Exception: " << exception.what() << "\n";
    exit(EXIT_FAILURE);
  }
}

std::vector<DDE::Shader> DDE::ShaderProgram::getShaderSources() const {
  return this->_shaderSources;
}

unsigned int DDE::ShaderProgram::getProgramObject() const {
  return this->_programObject;
}

bool DDE::ShaderProgram::_programLinkedSuccessfully(
    unsigned int programObject) const {
  int successfulLinking;

  glGetProgramiv(programObject, GL_LINK_STATUS, &successfulLinking);

  return successfulLinking;
}

void DDE::ShaderProgram::use() const { glUseProgram(this->_programObject); }

void DDE::ShaderProgram::_linkProgram(std::vector<Shader> &sources) {
  this->_programObject = glCreateProgram();

  for (const Shader &source : sources) {
    glAttachShader(this->_programObject, source.getShaderObject());
  }

  glLinkProgram(this->_programObject);

  if (!this->_programLinkedSuccessfully(this->_programObject)) {

    char linkingLog[512];
    glGetProgramInfoLog(this->_programObject, 512, nullptr, linkingLog);

    std::stringstream ssError;
    ssError << "Failed to link shader program!\n"
            << "Shader Program Object ID: " << this->_programObject << "\n"
            << "Shader Object IDs:\n\n";

    for (const Shader &shader : sources) {
      ssError << shader.getShaderObject() << "\n";
    }
    ssError << "\nOpenGL Info Log:\n\n" << linkingLog << "\n";

    throw std::runtime_error(ssError.str());
  } else {
    for (const Shader &shader : sources) {
      glDeleteShader(shader.getShaderObject());
    }
  }
}
