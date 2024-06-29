#pragma once

#include <DDE/Graphics/Vertex/Vertex.hpp>
#include <Glad/glad/glad.h>
#include <vector>

namespace DDE {

/**
 * @class Shape
 *
 * This is the abstract base class for all of the primitive
 * shapes that can be rendered in the DDE library.
 */
class Shape {

protected:
  std::vector<float> _vertices;
  unsigned int _vertexBufferObject;
  unsigned int _vertexArrayObject;
  void _initializeGLObjects();
  virtual void _setUpVertexData(std::vector<float> &vertices) = 0;

public:
  virtual void render() = 0;
  Shape() = delete;
  Shape(std::initializer_list<float> vertices);
};

/**
 * @class Triangle
 *
 * This class is used to handle abstracting
 * the drawing of a Triangle Primitive in
 * OpenGL.
 */
class Triangle : Shape {

private:
  void _setUpVertexData(std::vector<float> &vertices);

public:
  Triangle(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo,
           DDE::Vertex &vertexThree);
  Triangle() = delete;
  ~Triangle() = default;

  void render();
};

class Quad : Shape {

private:
  void _setUpVertexData(std::vector<float> &vertices);

public:
  Quad(DDE::Vertex &vertexOne, DDE::Vertex &vertexTwo, DDE::Vertex &vertexThree,
       DDE::Vertex &vertexFour);
  Quad() = delete;
  ~Quad() = default;

  void render();
}

} // namespace DDE
