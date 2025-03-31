/* complete_three.h */

#pragma once

#include "complete_graph.h"
#include "ring.h"

namespace TriangulationPlanarEmbedding {

using CompleteThree = CompleteGraph<3>;
/*#define COMPLETE_THREE CompleteThree.getInstance()*/

class CompleteThreeResult : public Ring {
public:
  inline CompleteThreeResult() : Ring() {
    Ring::vertices_.resize(3, 0);
  }/* constructor default */
  inline I& u() {
    return Ring::vertices_[0];
  }/* u */
  inline I U() const {
    return Ring::vertices_[0];
  }/* U */
  inline I& v() {
    return Ring::vertices_[1];
  }/* v */
  inline I V() const {
    return Ring::vertices_[1];
  }/* V */
  inline I& w() {
    return Ring::vertices_[2];
  }/* w */
  inline I W() const {
    return Ring::vertices_[2];
  }/* W */
  inline CompleteThreeResult(const I u, const I v, const I w) {
    Ring::vertices_.resize(3, 0);
    this->set(u, v, w);
  }/* constructor */
  inline void set(const I u, const I v, const I w) {
    this->u() = u;
    this->v() = v;
    this->w() = w;
  }/* set */
  inline void clear() {
    this->set(0, 0, 0);
  }/* clear */
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    const I u = this->U();
    const I v = this->V();
    const I w = this->W();
    SHOW_VAR_ENDL(cout, u, v, w)
  }/* show */
};/* class CompleteThreeResult */

}/* namespace TriangulationPlanarEmbedding */
