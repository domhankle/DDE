#pragma once

#include <string>

class Shader {

private:
  unsigned int _program;
  std::string _sourceCode;
  unsigned int _type;
  std::string _extractShaderSource(std::string filePath) const;

public:
  unsigned int getProgram() const;
  unsigned int getType() const;
  std::string getSourceCode() const;

  Shader(std::string filePath);
  ~Shader();
  Shader() = delete;
};
