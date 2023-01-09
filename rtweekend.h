#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions
inline double deg2Rad(double degrees) {
  return degrees * pi / 180.0;
}

inline double randomDouble() { 
  return rand() / (RAND_MAX + 1.0);  
}

inline double randomDouble(double min, double max) {
  return min + (max - min) * randomDouble();
}

// Ensures value x stays within bounds min and max, hence "clamped"
inline double clamp(double x, double min, double max) {
  if (x < min) return min;
  if (x > max) return max;
  return x;
}

#endif