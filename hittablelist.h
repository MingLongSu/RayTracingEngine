#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable {
private:
std::vector<std::shared_ptr<Hittable>> hittableObjects;

public:
HittableList();
HittableList(std::shared_ptr<Hittable> newHittableObject);
void clear();
void add(std::shared_ptr<Hittable> newHittableObject);
virtual bool hit (const Ray& ray, double tMin, double tMax, HitRecord& record) const override;

};

#endif