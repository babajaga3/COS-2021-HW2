#pragma once

/* The Point2D class:
   Models a 2D location with one convenience function (+=).
*/

struct Point2D {
  float x;
  float y;
  Point2D();
  Point2D(float x, float y);
  void operator+=(const Point2D & dv);
};
