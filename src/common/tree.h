/* tree.h */

#pragma once

#include "debug.h"

namespace TriangulationPlanarEmbedding {

class TreeNode {
public:
  size_t index_;
  int parent_;
  VI children_;
public:
  inline TreeNode() : index_(0), parent_(-1) {
    children_.clear();
  }/* constructor default */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_SPACE(cout, index_, parent_)
    SHOW_VI_NAME_ENDL(cout, children_)
  }/* show */
  inline void addParent(const int parent) {
    parent_ = parent;
  }/* addParent */
  inline void addChild(const size_t child) {
    children_.emplace_back(child);
  }/* addChild */
};/* class TreeNode */

class Tree {
CLASS_5_FUNCTIONS(Tree, nodes_, root_)
public:
  inline void add(const size_t parent, const size_t child) {
    nodes_[parent].addChild(child);
    nodes_[child].addParent(parent);
  }/* add */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline void setSize(const size_t n) {
    nodes_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      nodes_[i].index_ = i;
    }/* for */
  }/* setSize */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    const auto& n = this->size();
    SHOW_VAR_ENDL(cout, n)
    for (size_t i = 0; i < n; ++i) {
      HINT_INDEX(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
protected:
  std::vector<TreeNode> nodes_;
  size_t root_; /* index of root node */
};/* class Tree */

}/* namespace TriangulationPlanarEmbedding */
