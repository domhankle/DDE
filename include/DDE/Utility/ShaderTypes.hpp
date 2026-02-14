#pragma once

#include <string>
namespace DDE {

// This enum is used to represent Shader Stages
enum ShaderStage { NONE = -1, UNLIT = 0, SCENE = 1, OBJECT = 2 };

/* This struct holds the DDE specific uniform variables that will be found in
   its shader source code */
struct ShaderUniform {
  inline static const std::string MODEL_MATRIX = "dde_model_matrix";
  inline static const std::string PROJECTION_MATRIX = "dde_projection_matrix";
  inline static const std::string VIEW_MATRIX = "dde_view_matrix";
};

} // namespace DDE
