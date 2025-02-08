#version 330

layout(location = 0) in vec4 dde_position;
layout(location = 1) in vec4 dde_color;
layout(location = 2) in vec4 dde_texture;

out vec4 vert_color;
out vec4 vert_texture;

void main() {
  vert_color = dde_color;
  vert_texture = dde_texture;
  gl_Position = vec4(dde_position);
}
