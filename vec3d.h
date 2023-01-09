#ifndef VEC3D_H
#define VEC3D_H

#include <cmath>
#include <iostream>

#include "rtweekend.h"

using std::sqrt;

class Vec3D {
private:
double vector[3];

public:
Vec3D();
Vec3D(double e0, double e1, double e2);

double x() const;
double y() const;
double z() const;

Vec3D operator-() const;
double operator[](int i) const;
double &operator[](int i);

Vec3D &operator+=(const Vec3D &other);

Vec3D &operator*=(const double mult);

Vec3D &operator/=(const double t);

double length() const;

double lengthSquared() const;

bool nearZero() const;

static Vec3D random();
static Vec3D random(double min, double max);

};

// Type aliases for Vec3D
using Point3D = Vec3D;  // 3D point
using Colour = Vec3D;   // RGB color

// -------------------------- Utilities ---------------------------------

inline std::ostream &operator<<(std::ostream &out, const Vec3D &vec) {
  return out << vec[0] << ' ' << vec[1] << ' ' << vec[2];
}

inline Vec3D operator+(const Vec3D &vec1, const Vec3D &vec2) {
  return Vec3D{ vec1[0] + vec2[0], vec1[1] + vec2[1], vec1[2] + vec2[2] };
}

inline Vec3D operator-(const Vec3D &vec1, const Vec3D &vec2) {
  return Vec3D{ vec1[0] - vec2[0], vec1[1] - vec2[1], vec1[2] - vec2[2] };
}

inline Vec3D operator*(const Vec3D &vec1, const Vec3D &vec2) {
  return Vec3D{ vec1[0] * vec2[0], vec1[1] * vec2[1], vec1[2] * vec2[2] };
}

inline Vec3D operator*(double mult, const Vec3D &vec) {
  return Vec3D{ mult * vec[0], mult * vec[1], mult * vec[2] };
}

inline Vec3D operator*(const Vec3D &vec, double mult) { 
  return mult * vec; 
}

inline Vec3D operator/(Vec3D vec, double mult) { 
  return (1 / mult) * vec; 
}

inline double dot(const Vec3D &vec1, const Vec3D &vec2) {
  return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

inline Vec3D cross(const Vec3D &vec1, const Vec3D &vec2) {
  return Vec3D{ vec1[1] * vec2[2] - vec1[2] * vec2[1],
                vec1[2] * vec2[0] - vec1[0] * vec2[2],
                vec1[0] * vec2[1] - vec1[1] * vec2[0] };
}

inline Vec3D unitVector(Vec3D v) { 
  return v / v.length(); 
}

inline Vec3D randomInUnitSphere() {
  while (true) {
    auto p = Vec3D::random(-1, 1);
    if (p.lengthSquared() >= 1) continue;
    return p;
  }
}

inline Vec3D randomUnitVector() {
  return unitVector(randomInUnitSphere());
}

inline Vec3D randomInHemisphere(const Vec3D& normal) {
  Vec3D inUnitSphere = randomInUnitSphere();

  // Checks if in the same hemisphere as normal
  if (dot(inUnitSphere, normal) > 0.0) {
    return inUnitSphere;
  }
  
  return -inUnitSphere;
}

inline Vec3D reflect(const Vec3D& vec, const Vec3D& n) {
  return vec - 2 * dot(vec, n) * n;
}

inline Vec3D refract(const Vec3D& R, const Vec3D& n, double etaiOverEtat) { 
    auto theta = fmin(dot(-R, n), 1.0);
    Vec3D rOutPerpendicular = etaiOverEtat * (R + theta * n);
    Vec3D rOutParallel = -sqrt(fabs(1.0 - rOutPerpendicular.lengthSquared())) * n;

    return rOutPerpendicular + rOutParallel;
}

inline Vec3D randomInUnitDisk() { 
  while (true) { 
    auto p = Vec3D{ randomDouble(-1, 1), randomDouble(-1, 1), 0 };  
    if (p.lengthSquared() >= 1) continue;
    return p;
  }  
}

#endif