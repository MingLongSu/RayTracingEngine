#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"
#include "ray.h"
#include "hittable.h"

class HitRecord;

class Material {
public:
virtual bool scatter(
  const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered
) const = 0;

};

class Metal : public Material {
private:
Colour albedo;
double fuzz;

public:
Metal(const Colour& alb, double f);
virtual bool scatter(
  const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered
) const override;

};

class Dielectric : public Material {
private:
double indexOfRefraction;
static double reflectance(double cosine, double refIndex);

public:
Dielectric(double ir);
virtual bool scatter(
  const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered
) const override;

};

class Lambertian : public Material {
private:
Colour albedo;

public:
Lambertian(const Colour& alb);
virtual bool scatter(
  const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered
) const override;

};

#endif