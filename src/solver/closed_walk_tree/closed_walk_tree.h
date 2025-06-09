/* closed_walk_tree.h */

#pragma once

#include "closed_walk_vector.h"
#include "../../common/tree.h"

namespace TriangulationPlanarEmbedding {

class ClosedWalkTree {
CLASS_5_FUNCTIONS(ClosedWalkTree, walks_, tree_)
protected:
  ClosedWalkVector walks_;
  Tree tree_;
public:
  inline ClosedWalkVector& getWalks() {
    return walks_;
  }/* getWalks */
  inline Tree& getTree() {
    return tree_;
  }/* getTree */
};/* class ClosedWalkTree */

}/* namespace TriangulationPlanarEmbedding */
