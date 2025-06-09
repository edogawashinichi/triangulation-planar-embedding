/* closed_walk.h */

/* a closed walk is a v-e-sequence with starting-vertex equal to ending-vertex */
/* here every closed walk is restricted to unitary counterclockwise direction */

/* vertices_: v-sequence omitting ending-vertex */

#pragma once

#include "../../common/debug.h"

namespace TriangulationPlanarEmbedding {

class ClosedWalk {
CLASS_5_FUNCTIONS(ClosedWalk, vertices_)
protected:
  VI vertices_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VI_ENDL(cout, vertices_)
  }/* show */
  inline ClosedWalk(const VI& vertices) : vertices_(vertices) {
  }/* constructor */
  inline void set(const VI& vertices) {
    vertices_ = vertices;
  }/* set */
  inline void clear() {
    vertices_.clear();
  }/* clear */
  inline const VI& getConst() const {
    return vertices_;
  }/* getConst */
  inline size_t getConst(const size_t index) const {
    /* assuming index valid */
    return vertices_[index];
  }/* getConst */
  inline void add(const size_t vertex) {
    vertices_.emplace_back(vertex);
  }/* add */
};/* class ClosedWalk */

}/* namespace TriangulationPlanarEmbedding */
