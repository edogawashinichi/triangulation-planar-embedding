/* ring_in_ring.h */

#pragma once

#include "../common/debug.h"
#include "../common/math.h"

namespace TriangulationPlanarEmbedding {

class NodeOnRing {
CLASS_5_FUNCTIONS(NodeOnRing, vertex_, parents_, indices_)
protected:
  I vertex_;
  PII parents_;/* in counterclockwise order */
  PII indices_;/* corresponding to parents on the outer ring */
public:
  inline NodeOnRing(const I vertex, const PII& parents, const PII& indices): vertex_(vertex), parents_(parents), indices_(indices) {
  }/* constructor */
  inline NodeOnRing(const I vertex, const I p, const I q, const I pi, const I qi) {
    vertex_ = vertex;
    parents_ = {p, q};
    indices_ = {pi, qi};
  }/* constructor */
  inline NodeOnRing(const I vertex): vertex_(vertex) {
    parents_ = {0, 0};
    indices_ = {0, 0};
  }/* constructor */
  inline bool isGuard() const {
    return this->hasParents();
  }/* isGuard */
  inline bool hasParents() const {
    return indices_ != PII({0, 0});
  }/* hasParents */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR(cout, vertex_)
    if (this->hasParents()) {
      cout << SPACE(1);
      SHOW_PAIR_WITH_PARENTH(cout, parents_)
    }
    SHOW_ENDL(cout, "")
  }/* show */
  inline I getVertex() const {
    return vertex_;
  }/* getVertex */
  inline const PII& getParents() const {
    return parents_;
  }/* getParents */
  inline const PII& getIndices() const {
    return indices_;
  }/* getIndices */
  inline VI getParentsVector() const {
    return {parents_.first, parents_.second};
  }/* getParentsVector */
};/* class NodeOnRing */

class RingInRing {
CLASS_5_FUNCTIONS(RingInRing, nodes_)
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < nodes_.size(); ++i) {
      HINT_INDEX(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
  inline void clear() {
    nodes_.clear();
  }/* clear */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline const NodeOnRing& getConst(const I index) const {
    /* assuming valid index */
    return nodes_[index];
  }/* getConst */
  inline size_t distinctSize() const {
    return this->distinctVertices().size();
  }/* distinctSize */
  inline void add(const NodeOnRing& node) {
    nodes_.emplace_back(node);
  }/* add */
  inline void add(const I vertex) {
    this->add(NodeOnRing(vertex));
  }/* add */
  inline void add(const I vertex, const I p, const I q, const I pi, const I qi) {
    this->add(NodeOnRing(vertex, p, q, pi, qi));
  }/* add */
  inline bool isOutermost() const {
    for (const auto& node : nodes_) {
      if (node.hasParents()) return false;
    }/* for */
    return true;
  }/* isOutermost */
  inline void add(const VI& vertices) {
    for (const auto& vertex : vertices) {
      this->add(vertex);
    }/* for */
  }/* add */
  inline VI getVertices() const {
    /* WARNING: vertices may have duplicate
                even if not on the innermost ring */
    VI res;
    for (const auto& node : nodes_) {
      res.emplace_back(node.getVertex());
    }/* for */
    return res;
  }/* getVertices */
  inline VI distinctVertices() const {
    /* remove duplicate while maintaining the order */
    VI res;
    for (const auto& node : nodes_) {
      const I vertex = node.getVertex();
      if (find_element_in_vector<I>(vertex, res)) continue;
      res.emplace_back(vertex);
    }/* for */
    return res;
  }/* distinctVertices */
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
    cout << "the structure of RingResult" << HINT;
    for (size_t i = 0; i < rings_.size(); ++i) {
      cout << rings_[i].distinctSize() << SEPAR(1);
    }/* for */
    cout << ENDL;
  }/* showStructure */
  inline void add(const RingInRing& ring) {
    rings_.emplace_back(ring);
  }/* add */
  inline size_t size() const {
    return rings_.size();
  }/* size */
  inline const RingInRing& getConst(const I index) const {
    /* assuming valid index */
    return rings_[index];
  }/* getConst */
};/* class RingResult */

}/* namespace TriangulationPlanarEmbedding */
