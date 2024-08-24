#version 330

layout(location = 0) in vec3 dde_position;

void main() {
  gl_Position = vec4(dde_position, 1.0f);
}
