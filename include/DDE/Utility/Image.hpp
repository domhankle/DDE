
#include <string>

#pragma once
namespace DDE {

// TODO: Look into making _imageData be std::unique_ptr
/**
 * @class Image
 *
 * This class is used to load images from disk and
 * utilize them within the DDE library abstractions.
 * It can also be used to hold instances of Images. Note
 * that any instances of the DDE::Image object have
 * to implement the Big 3 due to _imageData being a raw
 * pointer.
 */
class Image {
 private:
  // The raw image data provided by stb_image.
  unsigned char *_imageData;
  // The width of the image.
  int _width;
  // The height of the image.
  int _height;
  // The number of channels associated with the image.
  int _channelCount;
  // The file path to the image.
  std::string _filePath;

 public:
  static unsigned char *loadImage(std::string filePath);
  static void freeImage(unsigned char *data);

  unsigned char *getImageData() const;
  int getWidth() const;
  int getHeight() const;
  int getChannelCount() const;
  std::string getFilePath() const;

  Image() = delete;
  Image(std::string &filePath);
  ~Image();
  Image(Image &otherImage);
  Image &operator=(Image otherImage);

  /**
   * This function is utilized by the assignment operator
   * overload for this class. It will handle swapping the data
   * between two image objects.
   *
   * @param myImage The current image reference
   * @param otherImage The image reference to assign
   */
  inline void friend swap(Image &myImage, Image &otherImage) {
    using std::swap;

    swap(myImage._filePath, otherImage._filePath);
    swap(myImage._imageData, otherImage._imageData);
    swap(myImage._channelCount, otherImage._channelCount);
    swap(myImage._width, otherImage._width);
    swap(myImage._height, otherImage._height);
  }
};

}  // namespace DDE
