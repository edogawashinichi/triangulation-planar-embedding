/* graph.h */

/*
   undirected
   symmetry: containing edges of both (u,v) and (v,u)
   simple: no loops, no multi-edges
*/

#pragma once

#include "common/notation.h"
#include "common/terminal.h"

namespace TriangulationPlanarEmbedding {

class Graph {
CLASS_5_FUNCTIONS(Graph, n_, neighbors_)
public:
  inline void show(std::ostream& cout) const {
    SHOW_VAR_ENDL(cout, n_)
    SHOW_MIVI_ENDL(cout, neighbors_)
  }/* show */
  inline void clear() {
    neighbors_.clear();
    n_ = 0;
  }/* clear */
  inline void add(const I u, const I v) {
    if (neighbors_.count(u)) {
      neighbors_[u].emplace_back(v);
    } else {
      neighbors_[u] = {v};
    }/* if else */
  }/* add */
  inline bool checkSymmetry() {
    bool change = false;
    MIVI copy(neighbors_);
    for (const auto& kv : neighbors_) {
      /* TODO */
    }/* for */
    return true;
  }/* checkSymmetry */
  inline void setN(const I n) {
    n_ = n;
  }/* setN */
protected:
  I n_;/* number of vertices */
  MIVI neighbors_;
};/* class Graph */

}/* namespace TriangulationPlanarEmbedding */
