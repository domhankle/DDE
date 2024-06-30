
#include <string>

#pragma once
namespace DDE {

/**
 * @class Image
 *
 * This class is used to load images from disk and
 * utilize them within the DDE library abstractions.
 * It can also be used to hold instances of Images.
 */
class Image {

private:
  unsigned char *_imageData;
  int _width;
  int _height;
  int _channelCount;
  std::string _filePath;
  friend void swap(Image &myImage, Image &otherImage);

public:
  static unsigned char *loadImage(std::string filePath);
  static void freeImage(unsigned char *data);

  Image() = delete;
  Image(std::string &filePath);
  ~Image();
  Image(Image &otherImage);
  Image &operator=(Image otherImage);

  inline void friend swap(Image &myImage, Image &otherImage) {
    using std::swap;

    swap(myImage._filePath, otherImage._filePath);
    swap(myImage._imageData, otherImage._imageData);
    swap(myImage._channelCount, otherImage._channelCount);
    swap(myImage._width, otherImage._width);
    swap(myImage._height, otherImage._height);
  }
};

} // namespace DDE
