#version 330


uniform uvec4 colorValue = uvec4(1.0f, 1.0f, 1.0f, 1.0f);
out uvec4 color;

void main() {
  color = colorValue;
}

