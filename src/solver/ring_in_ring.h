/* ring_in_ring.h */

#pragma once

#include "../common/debug.h"

namespace TriangulationPlanarEmbedding {

class NodeOnRing {
CLASS_5_FUNCTIONS(NodeOnRing, vertex_, multi_parents_, index_of_mp_)
protected:
  I vertex_;
  VII multi_parents_;
  VII index_of_mp_;
public:
  inline void add(const I pi, const I qi, const I p, const I q) {
    index_of_mp_.emplace_back(PII({pi, qi}));
    multi_parents_.emplace_back(PII({p, q}));
  }/* add */
  inline bool isGuard() const {
    return this->hasParents();
  }/* isGuard */
  inline bool hasParents() const {
    return !multi_parents_.empty();
  }/* hasParents */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_ENDL(cout, vertex_)
    SHOW_VII_ENDL(cout, multi_parents_)
  }/* show */
};/* class NodeOnRing */

class RingInRing {
CLASS_5_FUNCTIONS(RingInRing, nodes_)
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < nodes_.size(); ++i) {
      HINT_INDEX_ENDL(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline void add(const NodeOnRing& node) {
    nodes_.emplace_back(node);
  }/* add */
  inline bool isOutermost() const {
    for (const auto& node : nodes_) {
      if (node.hasParents()) return false;
    }/* for */
    return true;
  }/* isOutermost */
protected:
  std::vector<NodeOnRing> nodes_;
};/* class RingInRing */

class RingResult {
CLASS_5_FUNCTIONS(RingResult, rings_)
protected:
  std::vector<RingInRing> rings_;
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
    cout << "this is the structure of RingResult" << HINT;
    for (size_t i = 0; i < rings_.size(); ++i) {
      cout << rings_[i].size() << SEPAR(1);
    }/* for */
    cout << ENDL;
  }/* showStructure */
  inline void add(const RingInRing& ring) {
    rings_.emplace_back(ring);
  }/* add */
  inline size_t size() const {
    return rings_.size();
  }/* size */
};/* class RingResult */

}/* namespace TriangulationPlanarEmbedding */
