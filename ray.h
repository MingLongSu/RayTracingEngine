#ifndef RAY_H
#define RAY_H

#include "vec3d.h"

class Ray {
private:
  Point3D origin;
  Vec3D direction;

public:
  Ray();
  Ray(const Point3D &origin, const Vec3D &direction);

  Point3D getOrigin() const;
  Vec3D getDirection() const;

  Point3D at(double mult) const;
};

#endif