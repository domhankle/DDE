#pragma once

#include <glm/vec3.hpp>

namespace DDE {
// These are the base axis' vector representations in space (X, Y, Z)
inline constexpr glm::vec3 X_AXIS_VECTOR = glm::vec3(1.0f, 0.0f, 0.0f);
inline constexpr glm::vec3 Y_AXIS_VECTOR = glm::vec3(0.0f, 1.0f, 0.0f);
inline constexpr glm::vec3 Z_AXIS_VECTOR = glm::vec3(0.0f, 0.0f, 1.0f);
inline constexpr glm::vec3 ORIGIN = glm::vec3(0.0f, 0.0f, 0.0f);
}; // namespace DDE
