#include "line.hh"

#include <cmath>
#include <string>
#include <sstream>

/** return distance of this point from other point */
double Line::length(void) const {
  return a.distance(b);
}

std::string Line::toString() const {
  //declaring s to be a stringstream allows usage similar to std::cout
  std::stringstream s;
  s << a.toString() << "-- " << b.toString(); //normal (x, y) format
  return s.str(); //return std::string underlying stringstream
}
