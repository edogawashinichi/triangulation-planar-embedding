/* graph.h */

/*
   undirected
   symmetry: containing edges of both (u,v) and (v,u)
   simple: no loops, no multi-edges
*/

#pragma once

#include "common/notation.h"
#include "common/terminal.h"
#include "common/math.h"

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
  inline bool symmetry(const I u, const I v) const {
    if (!neighbors_.count(v)) return false;
    return find_element_in_vector<I>(u, neighbors_.at(v));
  }/* symmetry */
  inline bool checkSymmetry() {
    bool change = false;
    MIVI copy(neighbors_);
    for (const auto& kv : neighbors_) {
      const I u = kv.first;
      for (const I v : kv.second) {
        if (this->symmetry(u, v)) continue;
        copy[v].emplace_back(u);
      }/* for v */
    }/* for kv */
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
