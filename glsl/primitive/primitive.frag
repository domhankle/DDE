#version 330

in vec4 vert_color;
in vec4 vert_texture;

out vec4 frag_color;

void main() {
  frag_color = vert_color;
}

