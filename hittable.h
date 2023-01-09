#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class Material;

class HitRecord {
private:
Point3D point;  // Point of intersection
Vec3D normal;
std::shared_ptr<Material> matPtr; // Tells us how the rays should interact
double t;
bool frontFacing;

public:
HitRecord();
Point3D getPoint() const;
void setPoint(Point3D p);
Vec3D getNormal() const;
void setNormal(Vec3D n);
double getT() const;
void setT(double mult);
void setFaceNormal(const Ray& ray, const Vec3D& outwardNormal);
void setMaterial(std::shared_ptr<Material> mat);
std::shared_ptr<Material> getMaterial() const;
bool getFrontFacing() const;

};

class Hittable {
public:
virtual bool hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const = 0;
};

#endif