#include "vec3d.h"

Vec3D::Vec3D() : vector{ 0, 0, 0 } {}
Vec3D::Vec3D(double e0, double e1, double e2) : vector{ e0, e1, e2 } {}

double Vec3D::x() const { return vector[0]; }
double Vec3D::y() const { return vector[1]; }
double Vec3D::z() const { return vector[2]; }

Vec3D Vec3D::operator-() const { 
  return Vec3D{ -vector[0], -vector[1], -vector[2] }; 
}
double Vec3D::operator[](int i) const { return vector[i]; }
double& Vec3D::operator[](int i) { return vector[i]; }

Vec3D& Vec3D::operator+=(const Vec3D &other) {
  vector[0] += other[0];
  vector[1] += other[1];
  vector[2] += other[2];
  return *this;
}

Vec3D& Vec3D::operator*=(const double mult) {
  vector[0] *= mult;
  vector[1] *= mult;
  vector[2] *= mult;
  
  return *this;
}

Vec3D& Vec3D::operator/=(const double t) { 
  return *this *= 1 / t; 
}

double Vec3D::length() const { 
  return sqrt(lengthSquared()); 
}

double Vec3D::lengthSquared() const {
  return vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2];
}

Vec3D Vec3D::random() {
  return Vec3D{ randomDouble(), randomDouble(), randomDouble() };
}

Vec3D Vec3D::random(double min, double max) {
  return Vec3D{ randomDouble(min, max), randomDouble(min, max), randomDouble(min, max) };
}

bool Vec3D::nearZero() const {
  // Returns true if vector is near zero in all components
  const auto s = 1e-8;
  
  return (fabs(vector[0]) < s && fabs(vector[1]) < s && fabs(vector[2]) < s);
}
