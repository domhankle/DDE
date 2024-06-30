#include <DDE/Utility/Image.hpp>
#include <sstream>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

/**
 * This function is used to extract image data from a specified
 * file path that will be utilized inside of OpenGL functions.
 * Note that when using this static function, the caller is responsible
 * for also calling Image::freeImage on the pointer returned. This function
 * also prevents the caller from having access to width, height, and channels
 * information. Usually this function is just utilized to get image data,
 * if you need more than that, then instantiate an Image object.
 *
 * @param filePath A path to the image file to be loaded
 *
 * @returns image data for the specified file path
 */
unsigned char *DDE::Image::loadImage(std::string filePath) {

  // Flip images vertically on load
  stbi_set_flip_vertically_on_load(true);

  // Setting up stbi variables
  int width, height, channels;
  const char *imagePath = filePath.c_str();

  // Retrieving image data
  unsigned char *image = stbi_load(imagePath, &width, &height, &channels, 0);

  // If the image failed to load, we will throw a runtime error
  if (image == nullptr) {

    std::stringstream ssError;

    ssError << "Failed to load image from file path: " << filePath << "\n";

    throw std::runtime_error(ssError.str());
  }

  return image;
}

void DDE::Image::freeImage(unsigned char *data) {
  if (data == nullptr) {
    std::stringstream ssError;

    ssError << "Failed to free image data!\n";

    throw std::runtime_error(ssError.str());
  }

  stbi_image_free(data);
}

DDE::Image::Image(std::string &filePath)
    : _imageData(nullptr), _width(0), _height(0), _channelCount(0),
      _filePath(filePath) {
  this->_imageData = stbi_load(filePath.c_str(), &this->_width, &this->_height,
                               &this->_channelCount, 0);

  if (this->_imageData == nullptr) {
    std::stringstream ssError;

    ssError << "Failed to load image from file path: " << filePath << "\n";

    throw std::runtime_error(ssError.str());
  }
}

DDE::Image::~Image() {
  delete this->_imageData;
  this->_imageData = nullptr;
}

DDE::Image::Image(Image &otherImage)
    : _width(otherImage._width), _height(otherImage._height),
      _channelCount(otherImage._channelCount), _filePath(otherImage._filePath),
      _imageData(nullptr) {

  delete otherImage._imageData;
  otherImage._imageData = nullptr;

  this->_imageData = Image::loadImage(this->_filePath);
}

DDE::Image &DDE::Image::operator=(Image otherImage) {
  swap(*this, otherImage);
  return *this;
}

int DDE::Image::getWidth() const { return this->_width; }
int DDE::Image::getHeight() const { return this->_height; }
int DDE::Image::getChannelCount() const { return this->_channelCount; }
std::string DDE::Image::getFilePath() const { return this->_filePath; }
unsigned char *DDE::Image::getImageData() const { return this->_imageData; }
