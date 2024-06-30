
#include <string>

#pragma once
namespace DDE {

/**
 * @class ImageLoader
 *
 * This class is used to load images from disk and
 * utilize them within the DDE library abstractions.
 */
class ImageLoader {

public:
  static unsigned char *loadImage(std::string filePath);
  static void freeImage(unsigned char *data);
};

} // namespace DDE
