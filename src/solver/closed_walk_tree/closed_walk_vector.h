/* closed_walk_vector.h */

#pragma once

#include "closed_walk.h"

namespace TriangulationPlanarEmbedding {

class ClosedWalkVector {
CLASS_5_FUNCTIONS(ClosedWalkVector, walks_)
protected:
  std::vector<ClosedWalk> walks_;
public:
  inline ClosedWalk& getInnermostWalk() {
    if (walks_.empty()) {
      walks_.emplace_back(ClosedWalk());
    }/* if */
    return walks_[0];
  }/* getInnermostWalk */
  inline ClosedWalk& getSubinnermostWalk() {
    while (walks_.size() < 2) {
      walks_.emplace_back(ClosedWalk());
    }/* while */
    return walks_[1];
  }/* getSubinnerWalk */
};/* class ClosedWalkVector */

} /* namespace TriangulationPlanarEmbedding */
