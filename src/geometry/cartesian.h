/* cartesian.h */

/* cartesian coordinate system */

#pragma once

#include "../common/notation.h"

#include <cmath>

namespace TriangulationPlanarEmbedding {

class PlanarVector {
CLASS_5_FUNCTIONS(PlanarVector, x_, y_)
public:
  float x_;
  float y_;
public:
  inline PlanarVector(const F x, const F y): x_(x), y_(y) {
  }/* constructor */
  inline float length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
  }/* length */
};/* class PlanarVector */

class Point {
CLASS_5_FUNCTIONS(Point, x_, y_)
public:
  float x_;
  float y_;
public:
  inline Point(const F x, const F y): x_(x), y_(y) {
  }/* constructor */
  inline friend PlanarVector operator-(const Point& A, const Point& B) {
    return PlanarVector(A.x_ - B.x_, A.y_ - B.y_);
  }/* friend operator- */
  inline float distance(const Point& rhs) const {
    return (*this - rhs).length();
  }/* distance */
};/* class Point */

}/* namespace TriangulationPlanarEmbedding */
