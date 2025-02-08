#include <DDE/Graphics/Vertex/Vec4.hpp>
#include <sstream>

/**
 * Constructor for Vec4 object
 */
DDE::Vec4::Vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

/**
 * This allows for easy comparison of Vec4 objects
 *
 * @returns True - The two Vec4 objects are equivalent
 *          False - The two Vec4 objects are NOT equivalent
 */
bool DDE::Vec4::operator==(DDE::Vec4 &rhs) {
  return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z &&
         this->w == rhs.w;
}

/**
 * This is utilized to print a Vec4 object to the console.
 *
 * @returns A string that represents the Vec4 object
 */
std::string DDE::Vec4::print() const {

  std::stringstream ss;
  ss << "( " << this->x << ", " << this->y << ", " << this->z << ", " << this->w
     << ")" << std::endl;

  return ss.str();
}
