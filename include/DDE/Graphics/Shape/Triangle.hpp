#pragma once
#include <DDE/Engine/ShaderEngine.hpp>
#include <DDE/Graphics/Shape/Shape.hpp>

namespace DDE {

/**
 * @class Triangle
 *
 * This class is used to handle abstracting
 * the drawing of a Triangle Primitive in
 * OpenGL.
 */
class Triangle : public DDE::Shape {

private:
  void _setUpVertexData(std::vector<float> &vertices);

public:
  Triangle(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
           DDE::Vertex &vertexThree);
  Triangle() = delete;
  ~Triangle() = default;

  void render();
};
} // namespace DDE
