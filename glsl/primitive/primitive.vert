#version 330

layout(location = 0) in vec4 dde_position;
layout(location = 1) in vec4 dde_color;

out vec4 vert_color;

void main() {
  vert_color = dde_color;
  gl_Position = vec4(dde_position);
}
