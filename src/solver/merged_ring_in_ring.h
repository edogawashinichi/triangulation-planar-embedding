/* merged_ring_in_ring.h */

#pragma once

#include "../common/debug.h"
#include "../common/math.h"
#include "ring_in_ring.h"

namespace TriangulationPlanarEmbedding {

class MergedNodeOnRing {
CLASS_4_FUNCTIONS(MergedNodeOnRing, vertex_, multi_parents_, multi_indices_)
protected:
  I vertex_;
  VII multi_parents_;
  VII multi_indices_;
public:
  inline MergedNodeOnRing() {
    vertex_ = 0;
    multi_parents_.clear();
    multi_indices_.clear();
  }/* constructor default */
  inline MergedNodeOnRing(const I vertex) {
    vertex_ = vertex;
    multi_parents_.clear();
    multi_indices_.clear();
  }/* constructor */
  inline MergedNodeOnRing(const I v, const I p, const I q, const I pi, const I qi) {
    vertex_ = v;
    multi_parents_ = {{p, q}};
    multi_indices_ = {{pi, qi}};
  }/* constructor */
  inline void add(const I p, const I q, const I pi, const I qi) {
    multi_parents_.emplace_back(PII({p, q}));
    multi_indices_.emplace_back(PII({pi, qi}));
  }/* add */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR(cout, vertex_)
    cout << SPACE(1);
    SHOW_VII_ENDL(cout, multi_parents_)
  }/* show */
  inline size_t getVertex() const {
    return vertex_;
  }/* for */
};/* class MergedNodeOnRing */

class MergedRingInRing {
CLASS_5_FUNCTIONS(MergedRingInRing, nodes_)
protected:
  std::vector<MergedNodeOnRing> nodes_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < nodes_.size(); ++i) {
      HINT_INDEX(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline VI getVertices() const {
    VI res;
    for (const auto& node : nodes_) {
      res.emplace_back(node.getVertex());
    }/* for */
    return res;
  }/* getVertices */
  inline void clear() {
    nodes_.clear();
  }/* clear */
  inline void add(const NodeOnRing& node) {
    const auto& vertex = node.getVertex();
    const auto& parents = node.getParents();
    const auto& indices = node.getIndices();
    this->add(vertex, parents.first, parents.second, indices.first, indices.second);
  }/* add */
  inline void add(const VI& vertices) {
    for (const auto& vertex : vertices) {
      this->add(vertex);
    }/* for */
  }/* add */
  inline void add(const I vertex) {
    nodes_.emplace_back(MergedNodeOnRing(vertex));
  }/* add */
  inline void add(const I vertex, const I p, const I q, const I pi, const I qi) {
    const VI& vertices = this->getVertices();
    const int index = find_index_in_vector<I>(vertex, vertices);
    if (-1 == index) {
      nodes_.emplace_back(MergedNodeOnRing(vertex, p, q, pi, qi));
    } else {
      nodes_[index].add(p, q, pi, qi);
    }/* else */
  }/* add */
};/* class MergedRingInRing */

class MergedRingResult {
CLASS_5_FUNCTIONS(MergedRingResult, rings_)
protected:
  std::vector<MergedRingInRing> rings_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < rings_.size(); ++i) {
      HINT_INDEX_ENDL(cout, i)
      rings_[i].show(cout);
    }/* for */
  }/* show */
  inline void showStructure(std::ostream& cout) const {
    TEST_RETURN
    cout << "the structure of MergedRingResult" << HINT;
    for (size_t i = 0; i < rings_.size(); ++i) {
      cout << rings_[i].size() << SEPAR(1);
    }/* for */
    cout << ENDL;
  }/* showStructure */
  inline void add(const MergedRingInRing& ring) {
    rings_.emplace_back(ring);
  }/* add */
};/* class MergedRingResult */

}/* namespace TriangulationPlanarEmbedding */
