#pragma once

#include <string>

class Shader {

private:
  unsigned int _program;
  std::string _sourceCode;
  std::string _extractShaderSource(std::string filePath) const;

public:
  unsigned int getProgram() const;
  std::string getSourceCode() const;
  Shader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath,
         std::string geometryShaderFilePath = "",
         std::string tessellationShaderFilePath = "",
         std::string computeShaderFilePath = "");
  ~Shader();

  Shader() = delete;
};
