/* graph.h */

/*
   undirected
   symmetry: containing edges of both (u,v) and (v,u)
   simple: no loops, no multi-edges
*/

#pragma once

#include "common/notation.h"
#include "common/terminal.h"
#include "common/debug.h"
#include "common/math.h"

namespace TriangulationPlanarEmbedding {

class Graph {
CLASS_5_FUNCTIONS(Graph, n_, neighbors_)
public:
  inline Graph(const size_t n, const VVI& edges) {
    n_ = n;
    for (const auto& edge : edges) {
      this->addSymmetry(edge[0], edge[1]);
    }/* for */
  }/* constructor */
  inline virtual void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_ENDL(cout, n_)
    SHOW_MIVI_ENDL(cout, neighbors_)
  }/* show */
  inline void clear() {
    neighbors_.clear();
    n_ = 0;
  }/* clear */
  inline void add(const I u, const I v) {
    /* add edge (u,v) */
    /* may not guarantee symmetry */
    MAP_ADD(neighbors_, u, v)
  }/* add */
  inline void addSymmetry(const I u, const I v) {
    this->add(u, v);
    this->add(v, u);
  }/* addSymmetry */
  inline bool containEdge(const I u, const I v) const {
    if (!neighbors_.count(u)) return false;
    return find_element_in_vector<I>(v, neighbors_.at(u));
  }/* containEdge */
  inline VII getEdges() const {
    VII res;
    for (const auto& kv : neighbors_) {
      const I u = kv.first;
      for (const I& v : kv.second) {
        if (u >= v) continue;
        res.emplace_back(PII({u, v}));
      }/* for v */
    }/* for kv */
    return res;
  }/* getEdges */
  inline bool symmetry(const I u, const I v) const {
    /* assuming the graph contains (u,v) */
    /* to determing whether it contains (v,u) */
    return this->containEdge(v, u);
  }/* symmetry */
  inline bool checkSymmetry() {
    /* to check whether the graph is symmetry */
    /* make the graph symmetry if not */
    bool change = false;
    MIVI copy(neighbors_);
    for (const auto& kv : neighbors_) {
      const I u = kv.first;
      for (const I v : kv.second) {
        if (this->symmetry(u, v)) continue;
        MAP_ADD(copy, v, u)
        change = true;
      }/* for v */
    }/* for kv */
    std::swap(copy, neighbors_);
    return change;
  }/* checkSymmetry */
  inline void setN(const I n) {
    n_ = n;
  }/* setN */
  inline I n() const {
    return n_;
  }/* n */
  inline I m() const {
    /* number of edges */
    I res = 0;
    for (const auto& kv : neighbors_) {
      res += kv.second.size();
    }
    return res / 2;
  }/* m */
  inline VI neighbors(const I v) const {
    /* assuming valid v */
    return neighbors_.at(v);
  }/* neighbors */
  inline size_t size() const {
    return n_;
  }/* size */
protected:
  I n_;/* number of vertices */
  MIVI neighbors_;
};/* class Graph */

}/* namespace TriangulationPlanarEmbedding */
