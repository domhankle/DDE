#pragma once

#include <string>

namespace DDE {

class Shader {

private:
  std::string _sourceCode;
  unsigned int _type;
  unsigned int _shaderObject;
  bool _autoCompile;

  std::string _extractShaderSource(std::string &filePath) const;
  void _compileShaderObject(const char *sourceCode, unsigned int type);
  bool _shaderCompiledSuccessfully(unsigned int shaderObject) const;

public:
  unsigned int getType() const;

  unsigned int getShaderObject() const;

  std::string getSourceCode() const;
  void setSourceCode(std::string &filePath);

  bool isAutoCompiled() const;

  Shader(std::string &filePath, unsigned int shaderType,
         bool autoCompile = true);
  Shader(std::string &&filePath, unsigned int shaderType,
         bool autoCompile = true);
  ~Shader() = default;
  Shader() = delete;
  ;

  void compileShader(std::string &filePath);
};

} // namespace DDE
