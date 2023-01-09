#include "colour.h"

void writeColour(std::ostream &out, Colour pixelColour, int samplesPerPixel) {

  auto red = pixelColour.x();
  auto green = pixelColour.y();
  auto blue = pixelColour.z();

  // Divide colour by number of samples and applying gamma correction
  auto scale = 1.0 / samplesPerPixel;
  red = std::sqrt(scale * red);
  green = std::sqrt(scale * green);
  blue = std::sqrt(scale * blue);
  
  out << static_cast<int>(256 * clamp(red, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(green, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(blue, 0.0, 0.999)) << '\n';
}