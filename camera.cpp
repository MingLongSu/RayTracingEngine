#include "camera.h"

Camera::Camera(Point3D lookFrom, Point3D lookAt, Vec3D vUp, double vFov, double aspectRatio, double aperture, double focusDist) { 
  
  auto theta = deg2Rad(vFov);
  auto h = tan(theta / 2);
  auto viewportHeight = 2.0 * h ;
  auto viewportWidth = aspectRatio * viewportHeight;

  w = unitVector(lookFrom - lookAt); // New focalLength vector
  u  = unitVector(cross(vUp, w));
  v = cross(w, u);
  
  origin = lookFrom;
  horizontal = focusDist * viewportWidth * u;
  vertical = focusDist * viewportHeight * v;
  lowerLeftCorner = origin - horizontal/2 - vertical/2 - focusDist * w;

  lensRadius = aperture / 2;
}

Ray Camera::getRay(double s, double t) const {
  Vec3D rd = lensRadius  * randomInUnitDisk();
  Vec3D offset = u * rd.x() + v * rd.y();
  
  return Ray{ origin + offset, lowerLeftCorner + s*horizontal + t*vertical - origin - offset};
}
