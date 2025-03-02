#include "DDE/Graphics/Drawable.hpp"
#include <DDE/Graphics/Pencil/Pencil.hpp>
#include <DDE/Utility/DrawConfig/DrawConfig.hpp>
#include <cstdarg>

/**
 * This function is used to draw anything that inherits the
 * DDE::Drawable class to the screen. Any DDE::Drawable object
 * must have a "render" function implemented and specify a
 * shader stage to use.
 *
 * @param drawableObject the object to draw to the screen.
 * @param configs The additional draw configurations to utilize.
 */
