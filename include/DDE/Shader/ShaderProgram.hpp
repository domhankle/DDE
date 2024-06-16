#pragma once

#include <DDE/Shader/Shader.hpp>
#include <Glad/glad/glad.h>
#include <initializer_list>
#include <vector>

namespace DDE {

class ShaderProgram {
private:
  std::vector<DDE::Shader> _shaderSources;
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
