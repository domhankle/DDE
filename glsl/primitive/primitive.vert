#version 330

layout(location = 0) in vec4 dde_position;
layout(location = 1) in vec4 dde_color;
layout(location = 2) in vec4 dde_texture;

out vec4 vert_color;

mat4 dde_mvp_matrix;
uniform mat4 dde_model_matrix;
uniform mat4 dde_projection_matrix;
uniform mat4 dde_view_matrix;

void main() {
  vert_color = dde_color;

  dde_mvp_matrix = dde_projection_matrix * dde_view_matrix * dde_model_matrix;
  gl_Position = dde_mvp_matrix * dde_position;
}
