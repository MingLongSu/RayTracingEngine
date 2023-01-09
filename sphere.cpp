#include "sphere.h"

Sphere::Sphere() {}

Sphere::Sphere(Point3D c, double rad, std::shared_ptr<Material> mat) 
  : center{ c }, radius{ rad }, matPtr{ mat } {}

bool Sphere::hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const {
  Vec3D oc = ray.getOrigin() - center;
  auto a = ray.getDirection().lengthSquared();
  auto halfB = dot(oc, ray.getDirection());
  auto c = oc.lengthSquared() - radius * radius;
  
  auto discriminant = halfB * halfB - a*c;
  if (discriminant < 0) return false; 
  auto discriminantSqrt = sqrt(discriminant);

  auto root = (-halfB - discriminantSqrt) / a;
  // Check if current root is within bounds
  if (root < tMin || root > tMax) { 

    // Computing other root
    root = (-halfB + discriminantSqrt) / a;

    // Check if other root is within bounds
    if (root < tMin || root > tMax) {
      return false;
    }
  }

  record.setT(root);
  record.setPoint(ray.at(record.getT()));

  // (Point of intersection - center of sphere) / radius = unit normal
  record.setFaceNormal(ray, (record.getPoint() - center) / radius); 
  record.setMaterial(matPtr);
  
  return true;
}
