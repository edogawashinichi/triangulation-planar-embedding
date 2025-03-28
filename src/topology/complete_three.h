/* complete_three.h */

#pragma once

#include "complete_graph.h"

namespace TriangulationPlanarEmbedding {

using CompleteThree = CompleteGraph<3>;

class CompleteThreeResult {
CLASS_4_FUNCTIONS(CompleteThreeResult, u_, v_, w_)
public:
  I u_, v_, w_;
public:
  inline CompleteThreeResult() {
    this->set(0, 0, 0);
  }/* constructor default */
  inline CompleteThreeResult(const I u, const I v, const I w): u_(u), v_(v), w_(w) {
  }/* constructor */
  inline void set(const I u, const I v, const I w) {
    u_ = u; v_ = v; w_ = w;
  }/* set */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_ENDL(cout, u_, v_, w_)
  }/* show */
};/* class CompleteThreeResult */

}/* namespace TriangulationPlanarEmbedding */
