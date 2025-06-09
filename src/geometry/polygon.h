/* polygon.h */

#pragma once

#include "cartesian.h"
#include "../common/global.h"
#include <cmath>

namespace TriangulationPlanarEmbedding {

class Triangle {
CLASS_5_FUNCTIONS(Triangle, A_, B_, C_)
protected:
  Point A_;
  Point B_;
  Point C_;
public:
  inline void clear() {
    A_ = Point(0.0f, 0.0f);
    B_ = Point(0.0f, 0.0f);
    C_ = Point(0.0f, 0.0f);
  }/* clear */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    A_.show(cout);
    B_.show(cout);
    C_.show(cout);
  }/* show */
  inline Triangle(const Point& A, const Point& B, const Point& C) {
    A_ = A;
    B_ = B;
    C_ = C;
  }/* constructor */
  inline Triangle(const VFF& points) {
    this->set(points);
  }/* constructor */
  inline void set(const F Ax, const F Ay, const F Bx, const F By, const F Cx, const F Cy) {
    A_ = std::move(Point(Ax, Ay));
    B_ = std::move(Point(Bx, By));
    C_ = std::move(Point(Cx, Cy));
  }/* set */
  inline void set(const VFF& points) {
    A_ = std::move(Point(points[0].first, points[0].second));
    B_ = std::move(Point(points[1].first, points[1].second));
    C_ = std::move(Point(points[2].first, points[2].second));
  }/* set */
  inline Vector Va() const {
    return C_ - B_;
  }/* Va */
  inline Vector Vb() const {
    return A_ - C_;
  }/* Vb */
  inline Vector Vc() const {
    return B_ - A_;
  }/* Vc */
  inline F a() const {
    return this->Va().length();
  }/* a */
  inline F b() const {
    return this->Vb().length();
  }/* b */
  inline F c() const {
    return this->Vc().length();
  }/* c */
  inline F area() const {
    const auto& aa = this->a();
    const auto& bb = this->b();
    const auto& cc = this->c();
    const auto& q = (aa + bb + cc) / 2.0f;
    return sqrt(q * (q - aa) * (q - bb) * (q - cc));
  }/* area */
  inline F perimeter() const {
    return this->a() + this->b() + this->c();
  }/* perimeter */
};/* class Triangle */

class Polygon {
CLASS_5_FUNCTIONS(Polygon, points_)
protected:
  std::vector<Point> points_;
public:
  inline const Point& getConst(const I index) const {
    /* assuming valid index */
    return points_[index];
  }/* getConst */
  inline size_t size() const {
    return points_.size();
  }/* size */
  inline virtual void show(std::ostream& cout) const {
    TEST_RETURN
    for (I i = 0; i < points_.size(); ++i) {
      HINT_INDEX(cout, i)
      points_[i].show(cout);
    }/* for */
  }/* show */
  inline void zoom(const F& ratio) {
    for (auto& point : points_) {
      point.zoom(ratio);
    }/* for */
  }/* zoom */
  inline void rotate(const F& alpha) {
    /* alpha: counterclockwise radians */
    for (auto& point : points_) {
      point.rotate(alpha);
    }/* for */
  }/* rotate */
};/* class Polygon */

class RegularPolygon : public Polygon{
public:
  inline RegularPolygon(const RegularPolygon& rhs) : Polygon(rhs) {
  }/* constructor deepcopy */
  inline RegularPolygon(const I n) {
    this->set(n, 1, 0);
  }/* constructor */
  inline RegularPolygon(const I n, const F r) {
    this->set(n, r, 0);
  }/* constructor */
  inline void set(const I n, const F r, const F a) {
    /* n: number of points */
    /* r: radius of circumcircle */
    /* a: counterclockwise rotation radians */
    points_.resize(n);
    for (I i = 0; i < n; ++i) {
      const F theta = PI * 2.0f * i / n;
      const F x = r * cos(theta + a);
      const F y = r * sin(theta + a);
      points_[i] = std::move(Point(x, y));
    }/* for */
  }/* set */
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    cout << "this is a regular polygon" << ENDL;
    Polygon::show(cout);
  }/* show */
  inline F areaRRS() const {
    /* the area of triangle RRS */
    /* R represents one radius */
    /* S represents one side */
    Point o(0.0f, 0.0f);
    return Triangle(o, points_[0], points_[1]).area();
  }/* areaRRS */
  inline F areaSSC() const {
    /* the area of triangle SSC */
    /* S represents one side */
    /* C represents one chord connecting consecutive sides */
    return Triangle(points_[0], points_[1], points_[2]).area();
  }/* areaSSC */
};/* class RegularPolygon */

}/* namespace TriangulationPlanarEmbedding */
