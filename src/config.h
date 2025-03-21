/* config.h */

#pragma once

#include "common/notation.h"
#include "common/terminal.h"

namespace TriangulationPlanarEmbedding {

class Config {
CLASS_5_FUNCTIONS(Config, min_dist_, min_area_)
public:
  inline void show(std::ostream& cout) const {
    SHOW_VAR_ENDL(cout, min_dist_)
    SHOW_VAR_ENDL(cout, min_area_)
  }/* show */
  inline void clear() {
    min_dist_ = 0.0f;
    min_area_ = 0.0f;
  }/* clear */
public:
  F min_dist_;
  F min_area_;
};/* class Config */

}/* namespace TriangulationPlanarEmbedding */
