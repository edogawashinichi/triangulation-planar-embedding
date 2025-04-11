/* config.h */

#pragma once

#include "common/notation.h"
#include "common/terminal.h"
#include "common/debug.h"

namespace TriangulationPlanarEmbedding {

class Config {
CLASS_5_FUNCTIONS(Config, min_dist_, min_area_)
public:
  inline Config(const F dist, const F area) {
    min_dist_ = dist;
    min_area_ = area;
  }/* constructor */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_ENDL(cout, min_dist_)
    SHOW_VAR_ENDL(cout, min_area_)
  }/* show */
  inline void clear() {
    min_dist_ = 0.0f;
    min_area_ = 0.0f;
  }/* clear */
  inline F getMinDist() const {
    return min_dist_;
  }/* getMinDist */
  inline F getMinArea() const {
    return min_area_;
  }/* getMinArea */
public:
  F min_dist_;
  F min_area_;
};/* class Config */

}/* namespace TriangulationPlanarEmbedding */
