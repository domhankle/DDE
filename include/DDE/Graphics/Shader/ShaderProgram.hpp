#pragma once

#include <DDE/Graphics/Shader/Shader.hpp>
#include <Glad/glad/glad.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
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

  void activate() const;

  int getUniformLocation(std::string uniformName) const;

  glm::mat4 getMatrix4x4Uniform(std::string uniformName) const;
  void setMatrix4x4Uniform(std::string uniformName, glm::mat4 matrix);

  glm::mat3 getMatrix3x3Uniform(std::string uniformName) const;
  void setMatrix3x3Uniform(std::string uniformName, glm::mat3 matrix);

  ShaderProgram(std::initializer_list<Shader> shaders);
  ShaderProgram() = delete;
  ~ShaderProgram() = default;
};

} // namespace DDE
