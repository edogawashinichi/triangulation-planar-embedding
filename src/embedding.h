/* embedding.h */

#pragma once

#include "common/notation.h"
#include "geometry/cartesian.h"
#include "common/terminal.h"
#include "common/debug.h"

namespace TriangulationPlanarEmbedding {

class Embedding {
CLASS_5_FUNCTIONS(Embedding, vertex2point_)
protected:
  UM<I, Point> vertex2point_;
public:
  inline Embedding(const MIPFF& data) {
    this->set(data);
  }/* constructor */
  inline void set(const MIPFF& data) {
    for (const auto& kv : data) {
      this->add(kv.first, Point(kv.second.first, kv.second.second));
    }/* for */
  }/* set */
  inline void add(const I vertex, const Point& point) {
    vertex2point_[vertex] = point;
  }/* add */
  inline Point getPoint(const I vertex) const {
    return vertex2point_.count(vertex) ? vertex2point_.at(vertex) : Point();
  }/* getPoint */
  inline const UM<I, Point>& getConst() const {
    return vertex2point_;
  }/* getConst */
  inline MIPFF getData() const {
    MIPFF res;
    for (const auto& kv : vertex2point_) {
      res[kv.first] = PFF({kv.second.x_, kv.second.y_});
    }/* for */
    return res;
  }/* getData */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_MIPFF_ENDL(cout, this->getData())
  }/* show */
};/* class Embedding */

}/* namespace TriangulationPlanarEmbedding */
