/* ring.h */

#pragma once

#include "../common/terminal.h"

namespace TriangulationPlanarEmbedding {

class Ring {
CLASS_5_FUNCTIONS(Ring, vertices_)
public:
  VI vertices_;
public:
  inline Ring(const VI& vertices): vertices_(vertices) {
  }/* constructor */
  inline virtual void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VI_ENDL(cout, vertices_)
  }/* show */
};/* class Ring */

}/* namespace TriangulationPlanarEmbedding */
