#pragma once

/* Object Class:
   This class should be used to model both the Player and the
   Enemies.
*/

#include<cmath>
#include"point.hpp"

class Object {
private:
  int id;
  Point2D loc;
  Point2D dir;
public:
  Object();
  Object(int id,
	 Point2D loc,
	 Point2D dir);
  int GetID() const;
  Point2D GetLoc() const;
  Point2D GetDir() const;
  void SetLoc(Point2D p);
  void SetDir(Point2D p);
  bool IsWithinCircle(Point2D c, float r);
  void Update();
};
