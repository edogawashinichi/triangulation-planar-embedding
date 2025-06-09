/* tree.h */

#pragma once

#include "debug.h"

namespace TriangulationPlanarEmbedding {

class TreeNode {
protected:
  size_t index_;
  int parent_;
  VI children_;
public:
  inline void setIndex(const size_t index) {
    index_ = index;
  }/* setIndex */
  inline TreeNode() : index_(0), parent_(-1) {
    children_.clear();
  }/* constructor default */
  inline TreeNode(const size_t index) : index_(index), parent_(-1) {
    children_.clear();
  }/* constructor */
  inline TreeNode(const size_t index, const size_t parent) : index_(index), parent_(parent) {
    children_.clear();
  }/* constructor */
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
    this->check(std::max(parent, child));
    nodes_[parent].addChild(child);
    nodes_[child].addParent(parent);
  }/* add */
  inline void check(const size_t index) {
    /* check whether nodes_[index] exists */
    /* allocate memory for nodes_[index] if not */
    for (size_t i = nodes_.size(); i <= index; ++i) {
      nodes_.emplace_back(TreeNode(i));
    }/* for */
  }/* check */
  inline void setRoot() {
    nodes_.clear();
    nodes_.emplace_back(TreeNode(0));
    root_ = 0;
  }/* setRoot */
  inline void setSubroot() {
    this->add(0, 1);
  }/* setSubroot */
  inline size_t size() const {
    return nodes_.size();
  }/* size */
  inline void setSize(const size_t n) {
    nodes_.resize(n);
    for (size_t i = 0; i < n; ++i) {
      nodes_[i].setIndex(i);
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
