#pragma once

#include <DDE/Shader/Shader.hpp>
#include <Glad/glad/glad.h>
#include <initializer_list>
#include <vector>

namespace DDE {

/**
 * @class ShaderProgram
 *
 * This class handles the abstraction of a program object
 * from OpenGL. It will attempt to link whatever Shader objects are
 * passed to it.
 */
class ShaderProgram {
private:
  // All of the shader objects attached to this program.
  std::vector<DDE::Shader> _shaderSources;
  // OpenGL program ID
  unsigned int _programObject;

  bool _programLinkedSuccessfully(unsigned int programObject) const;
  void _linkProgram(std::vector<Shader> &sources);

public:
  std::vector<DDE::Shader> getShaderSources() const;
  unsigned int getProgramObject() const;
  void use() const;

  ShaderProgram(std::initializer_list<Shader> shaders);

  ~ShaderProgram() = default;
  ShaderProgram() = delete;
};

} // namespace DDE
