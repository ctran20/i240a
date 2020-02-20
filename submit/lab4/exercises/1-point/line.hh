#ifndef LINE_HH_
#define LINE_HH_

#include <string>
#include "point.hh"

struct Line {
  //for the purpose of this lab, these fields are public but const.
  //Having them public makes it hard to change the reprentation
  //from these cartesian coordinates to polar coordinates.
  const Point a, b;

  /** constructor */
  Line(Point a, Point b) : a(a), b(b) { }

  /** return distance of this point from other point */
  //the trailing const means that this function will not change
  //this point
  double length(void) const;

  /** return a string representation of this point */
  std::string toString() const;
};



#endif //ifndef LINE_HH_
