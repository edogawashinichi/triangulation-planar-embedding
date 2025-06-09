/* walk_guard.h */

#pragma once

#include "../../common/debug.h"

/* TODO: AccWalkGuard */

namespace TriangulationPlanarEmbedding {

class GuardNode {
CLASS_5_FUNCTIONS(GuardNode, vertex_, parents_)
protected:
  size_t vertex_;
  VI parents_;
public:
  inline GuardNode(const size_t vertex) {
    vertex_ = vertex;
    parents_.clear();
  }/* constructor */
  inline GuardNode(const size_t vertex, const size_t parent, const size_t qarent) {
    vertex_ = vertex;
    parents_ = {parent, qarent};
  }/* constructor */
  inline const size_t& constVertex() const {
    return vertex_;
  }/* constVertex */
  inline const size_t& constParent() const {
    return parents_[0];
  }/* constParent */
  inline const size_t& constQarent() const {
    return parents_[1];
  }/* constQarent */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_SPACE(cout, vertex_)
    SHOW_VI_NAME_ENDL(cout, parents_)
  }/* show */
};/* class GuardNode */

class WalkGuardVector {
CLASS_5_FUNCTIONS(WalkGuardVector, nodes_)
protected:
  std::vector<GuardNode> nodes_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < nodes_.size(); ++i) {
      HINT_INDEX_ENDL(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
  inline const GuardNode& getConst(const size_t index) const {
    /* assuming index valid */
    return nodes_[index];
  }/* getConst */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline bool empty() const {
    return nodes_.empty();
  }/* empty */
  inline void clear() {
    nodes_.clear();
  }/* clear */
  inline void add(const size_t vertex) {
    nodes_.emplace_back(GuardNode(vertex));
  }/* add */
  inline void add(const size_t vertex, const size_t parent, const size_t qarent) {
    nodes_.emplace_back(GuardNode(vertex, parent, qarent));
  }/* add */
};/* class WalkGuardVector */

}/* namespace TriangulationPlanarEmbedding */
