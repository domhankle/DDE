#include <DDE/Utility/ImageLoader.hpp>
#include <sstream>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

/**
 * This function is used to extract image data from a specified
 * file path that will be utilized inside of OpenGL functions
 *
 * @param filePath A path to the image file to be loaded
 *
 * @returns image data for the specified file path
 */
unsigned char *DDE::ImageLoader::loadImage(std::string filePath) {

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

void DDE::ImageLoader::freeImage(unsigned char *data) {
  if (data == nullptr) {
    std::stringstream ssError;

    ssError << "Failed to free image data!\n";

    throw std::runtime_error(ssError.str());
  }

  stbi_image_free(data);
}
