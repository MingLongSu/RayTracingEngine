#include "hittablelist.h"

HittableList::HittableList() {}

HittableList::HittableList(std::shared_ptr<Hittable> newHittableObject) {
  add(newHittableObject);
}

void HittableList::clear() {
  hittableObjects.clear();
}

void HittableList::add(std::shared_ptr<Hittable> newHittableObject) {
  hittableObjects.push_back(newHittableObject);
}

bool HittableList::hit(const Ray& ray, double tMin, double tMax, HitRecord& record) const {
  HitRecord tempRecord;
  bool hitAnything = false;
  auto closestSoFar = tMax;

  for (const auto& hittableObject : hittableObjects) {
    if (hittableObject->hit(ray, tMin, tMax, tempRecord)) {
      hitAnything = true;
      closestSoFar = tempRecord.getT();
      record = tempRecord;
    }
  }

  return hitAnything;
}
