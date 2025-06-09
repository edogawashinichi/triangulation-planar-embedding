/* guard_path.h */

#pragma once

#include "walk_guard.h"

namespace TriangulationPlanarEmbedding {

class CitizenNode {
CLASS_5_FUNCTIONS(CitizenNode, vertex_, parent_)
protected:
  size_t vertex_;
  size_t parent_;
public:
  inline CitizenNode(const size_t vertex, const size_t parent) : vertex_(vertex), parent_(parent) {
  }/* constructor */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    SHOW_VAR_ENDL(cout, vertex_, parent_)
  }/* show */
  inline const size_t& constVertex() const {
    return vertex_;
  }/* constVertex */
  inline const size_t& constParent() const {
    return parent_;
  }/* constParent */
};/* class CitizenNode */

class GuardPath {
CLASS_5_FUNCTIONS(GuardPath, guard_start_, guard_end_, citizens_)
protected:
  GuardNode guard_start_;
  GuardNode guard_end_;
  std::vector<CitizenNode> citizens_;/* guard included */
public:
  inline const GuardNode& constGuardStart() const {
    return guard_start_;
  }/* constGuardStart */
  inline const CitizenNode& constCitizen(const size_t index) const {
    /* assuming index valid */
    return citizens_[index];
  }/* constCitizen */
  inline size_t size() const {
    return citizens_.size();
  }/* size */
  inline GuardPath(const GuardNode& guard_start, const GuardNode& guard_end, const std::vector<CitizenNode>& citizens) : guard_start_(guard_start), guard_end_(guard_end), citizens_(citizens) {}/* constructor */
  inline GuardPath(const GuardNode& guard_start, const GuardNode& guard_end, const size_t parent, const VI& path) : guard_start_(guard_start), guard_end_(guard_end) {
    for (const size_t vertex : path) {
      citizens_.emplace_back(CitizenNode(vertex, parent));
      /* guard included */
    }/* for */
  }/* constructor */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    guard_start_.show(cout);
    guard_end_.show(cout);
    for (size_t i = 0; i < citizens_.size(); ++i) {
      HINT_INDEX(cout, i)
      citizens_[i].show(cout);
    }/* for */
  }/* show */
};/* class GuardPath */

class GuardPathVector {
CLASS_5_FUNCTIONS(GuardPathVector, paths_)
protected:
  std::vector<GuardPath> paths_;
public:
  inline const GuardPath& getConst(const size_t index) const {
    /* assuming index valid */
    return paths_[index];
  }/* getConst */
  inline size_t size() const {
    return paths_.size();
  }/* size */
  inline bool empty() const {
    return paths_.empty();
  }/* empty */
  inline void clear() {
    paths_.clear();
  }/* clear */
  inline void add(const GuardPath& path) {
    paths_.emplace_back(path);
  }/* add */
  inline void add(const GuardNode& guard_start, const GuardNode& guard_end, const size_t parent, const VI& path) {
    this->add(GuardPath(guard_start, guard_end, parent, path));
  }/* add */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < paths_.size(); ++i) {
      HINT_INDEX_ENDL(cout, i)
      paths_[i].show(cout);
    }/* for */
  }/* show */
};/* class GuardPathVector */

}/* namespace TriangulationPlanarEmbedding */
