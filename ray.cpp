#include "ray.h"

Ray::Ray() {}

Ray::Ray(const Point3D& origin, const Vec3D& direction)
  : origin{ origin }, direction{ direction } {}

Point3D Ray::getOrigin() const { 
  return origin;
}

Vec3D Ray::getDirection() const {
  return direction;
}

Point3D Ray::at(double mult) const { 
  return origin + direction * mult;
}
