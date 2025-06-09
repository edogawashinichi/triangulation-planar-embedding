/* walk_triangle.h */

#pragma once

#include "../../common/debug.h"
#include "../../topology/complete_result.h"
#include "../../geometry/polygon.h"

namespace TriangulationPlanarEmbedding {

class TriangleNode {
CLASS_5_FUNCTIONS(TriangleNode, k3_, triangle_)
protected:
  CompleteThreeResult k3_;
  Triangle triangle_;
public:
  inline TriangleNode(const CompleteThreeResult& k3) : k3_(k3) {
    triangle_.clear();
  }/* constructor */
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    k3_.show(cout);
    triangle_.show(cout);
  }/* show */
};/* class TriangleNode */

class WalkTriangleVector {
CLASS_5_FUNCTIONS(WalkTriangleVector, nodes_)
protected:
  std::vector<TriangleNode> nodes_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    for (size_t i = 0; i < nodes_.size(); ++i) {
      HINT_INDEX_ENDL(cout, i)
      nodes_[i].show(cout);
    }/* for */
  }/* show */
  inline void clear() {
    nodes_.clear();
  }/* clear */
  inline void add(const TriangleNode& triangle) {
    nodes_.emplace_back(triangle);
  }/* add */
  inline void add(const CompleteThreeResult& k3) {
    nodes_.emplace_back(TriangleNode(k3));
  }/* add */
};/* class WalkTriangleVector */

}/* namespace TriangulationPlanarEmbedding */
