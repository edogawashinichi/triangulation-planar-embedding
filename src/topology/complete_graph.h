/* complete_graph.h */

#pragma once

#include "../graph.h"
#include "../common/debug.h"

namespace TriangulationPlanarEmbedding {

template<size_t N>
class CompleteGraph : public Graph {
public:
  inline CompleteGraph() : Graph() {
    Graph::setN(N);
    for (size_t i = 0; i < N; ++i) {
      for (size_t j = i + 1; j < N; ++j) {
        Graph::addSymmetry(i, j);
      }/* for j */
    }/* for i */
  }/* constructor default */
public:
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    const S info("this is a complete graph of size " + std::to_string(Graph::n_));
    SHOW_ENDL(cout, info)
  }/* show */
};/* class CompleteGraph */

}/* namespace TriangulationPlanarEmbedding */
