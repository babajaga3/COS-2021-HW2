#include"object.hpp"

Object::Object()
  : id(-1)
{}
Object::Object(int id,
       Point2D loc,
       Point2D dir)
  : id(id), loc(loc), dir(dir)
{}
int Object::GetID() const { return id; }
Point2D Object::GetLoc() const { return loc; }
Point2D Object::GetDir() const { return dir; }
void Object::SetLoc(Point2D p) { loc = p; }
void Object::SetDir(Point2D p) { dir = p; }
bool Object::IsWithinCircle(Point2D c, float r) {
  return std::sqrt(std::pow(c.x-loc.x, 2.0)+
		   std::pow(c.y-loc.y, 2.0)) <= r;
}
void Object::Update() {
  // The update method only updates the
  // object's position. A real update method
  // (or methods) would handle all sorts
  // of things.
  loc += dir;
}
