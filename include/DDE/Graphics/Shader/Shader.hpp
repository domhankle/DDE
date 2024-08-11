#pragma once

#include <string>

namespace DDE {

/**
 * @class Shader
 *
 * This class is meant to abstract the OpenGL Shader
 * object. It will attempt to compile Shader sources provided
 * in the constructor.
 */
class Shader {
 private:
  // Source code for this shader
  std::string _sourceCode;

  // The type of shader this is
  unsigned int _type;

  // The OpenGL shader object ID
  unsigned int _shaderObject;

  // Compile this shader when it's created
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

  void compileShader(std::string &filePath);
};

}  // namespace DDE
