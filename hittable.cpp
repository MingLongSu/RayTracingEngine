#include "hittable.h"

HitRecord::HitRecord() {}

Point3D HitRecord::getPoint() const { 
  return point;
}

Vec3D HitRecord::getNormal() const { 
  return normal;
}

double HitRecord::getT() const { 
  return t;  
}

void HitRecord::setPoint(Point3D p) { 
  point = p;
}

void HitRecord::setNormal(Vec3D n) { 
  normal = n;  
}

void HitRecord::setT(double mult) { 
  t = mult;  
}

void HitRecord::setFaceNormal(const Ray &ray, const Vec3D &outwardNormal) {
  frontFacing = dot(ray.getDirection(), outwardNormal) < 0;
  normal = frontFacing ? outwardNormal : -outwardNormal;
}

void HitRecord::setMaterial(std::shared_ptr<Material> mat) {
  matPtr = mat;
}

std::shared_ptr<Material> HitRecord::getMaterial() const {
  return matPtr;
}

bool HitRecord::getFrontFacing() const {
  return frontFacing;
}
