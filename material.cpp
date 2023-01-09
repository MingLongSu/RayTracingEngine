#include "material.h"

Metal::Metal(const Colour& alb, double f) 
  : albedo{ alb }, fuzz{ f } {}

bool Metal::scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const {
  Vec3D reflected = reflect(unitVector(ray.getDirection()), rec.getNormal() );
  scattered = Ray{ rec.getPoint(), reflected + fuzz * randomInUnitSphere() };
  attenuation = albedo;
  return dot(scattered.getDirection(), rec.getNormal()) > 0;
}

Dielectric::Dielectric(double ir) 
  : indexOfRefraction{ ir } {}

double Dielectric::reflectance(double cosine, double refIndex) {
  // Schlick approximation for reflectance
  auto r0 = (1 - refIndex) / (1 + refIndex);
  r0 = r0 * r0;

  return r0 + (1.0 - r0) * pow((1 - cosine), 5);
}

bool Dielectric::scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const {
  attenuation = Colour{ 1.0, 1.0, 1.0 };
  double refractionRatio = rec.getFrontFacing() ? (1.0 / indexOfRefraction) : indexOfRefraction;

  Vec3D unitDirection = unitVector(ray.getDirection());
  double cosTheta = fmin(dot(-unitDirection, rec.getNormal()), 1.0);
  double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

  bool isNotRefractable = refractionRatio * sinTheta > 1.0;
  Vec3D direction;

  if (isNotRefractable || (reflectance(cosTheta, refractionRatio) > randomDouble())) {
    direction = reflect(unitDirection, rec.getNormal());
  } else {
    direction = refract(unitDirection, rec.getNormal(), refractionRatio);
  }
  scattered = Ray{ rec.getPoint(), direction };
  
  return true;
}

Lambertian::Lambertian(const Colour& alb) 
  : albedo{ alb } {}

bool Lambertian::scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const {
  auto scatterDirection = rec.getNormal() + randomUnitVector();

  // Catches degenerate scatter directions
  if (scatterDirection.nearZero()) {
    scatterDirection = rec.getNormal();
  }
  
  scattered = Ray{ rec.getPoint(), scatterDirection };
  attenuation = albedo;

  return true;
}
