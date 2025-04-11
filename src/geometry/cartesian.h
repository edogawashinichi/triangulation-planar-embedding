/* cartesian.h */

/* plane cartesian coordinate system */

#pragma once

#include "../common/debug.h"
#include <cmath>

namespace TriangulationPlanarEmbedding {

class Vector {
CLASS_5_FUNCTIONS(Vector, x_, y_)
public:
  float x_;
  float y_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    const PFF& pair = {x_, y_};
    SHOW_PAIR_WITH_PARENTH_ENDL(cout, pair)
  }/* show */
  inline Vector(const F x, const F y): x_(x), y_(y) {
  }/* constructor */
  inline float length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
  }/* length */
  inline float lengthSquare() const {
    return x_ * x_ + y_ * y_;
  }/* lengthSquare */
};/* class Vector */

class Point {
CLASS_5_FUNCTIONS(Point, x_, y_)
public:
  float x_;
  float y_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    const PFF& pair = {x_, y_};
    SHOW_PAIR_WITH_PARENTH_ENDL(cout, pair)
  }/* show */
  inline Point(const F x, const F y): x_(x), y_(y) {
  }/* constructor */
  inline friend Vector operator-(const Point& A, const Point& B) {
    return Vector(A.x_ - B.x_, A.y_ - B.y_);
  }/* friend operator- */
  inline float distance(const Point& rhs) const {
    return (*this - rhs).length();
  }/* distance */
  inline float distanceSquare(const Point& rhs) const {
    return (*this - rhs).lengthSquare();
  }/* distanceSquare */
  inline void zoom(const F& ratio) {
    x_ *= ratio;
    y_ *= ratio;
  }/* zoom */
  inline void rotate(const F& alpha) {
    /* rotate vector (*this-O) where O is the origin */
    /* alpha: counterclockwise radians */
    const F& sina = sin(alpha);
    const F& cosa = cos(alpha);
    F x = x_ * cosa - y_ * sina;
    F y = x_ * sina + y_ * cosa;
    std::swap(x_, x);
    std::swap(y_, y);
  }/* rotate */
};/* class Point */

}/* namespace TriangulationPlanarEmbedding */
