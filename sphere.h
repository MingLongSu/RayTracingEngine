#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "hittable.h"

class Sphere : public Hittable { 
private:
Point3D center;
double radius;
std::shared_ptr<Material> matPtr;

public:
Sphere();
Sphere(Point3D c, double rad, std::shared_ptr<Material> mat);
virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const override;

};

#endif