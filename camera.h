#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class Camera {
private:
Point3D origin;
Point3D lowerLeftCorner;
Vec3D horizontal;
Vec3D vertical;
Vec3D u, v, w;
double lensRadius;

public:
Camera(
  Point3D lookFrom, 
  Point3D lookAt, 
  Vec3D vUp, 
  double vFov,
  double aspectRatio,
  double aperture,
  double focusDist
);
Ray getRay(double s, double t) const;

};

#endif