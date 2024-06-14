#include <DDE/Shader/Shader.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

std::string Shader::getSourceCode() const { return this->_sourceCode; }

unsigned int Shader::getProgram() const { return this->_program; }

unsigned int Shader::getType() const { return this->_type; }

Shader::Shader(std::string filePath) {}

std::string Shader::_extractShaderSource(std::string filePath) const {
  std::ifstream stream(filePath);
  std::stringstream buffer;

  buffer << stream.rdbuf();
}
