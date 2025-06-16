/* data.h */

#pragma once

#include "graph.h"
#include "mapper.h"

namespace TriangulationPlanarEmbedding {

class Data {
CLASS_5_FUNCTIONS(Data, graph_, mapper_)
protected:
  Graph graph_;
  Mapper mapper_;
public:
  inline void show(std::ostream& cout) const {
    TEST_RETURN
    const size_t n = graph_.n();
    SHOW_VAR_ENDL(cout, n)
    const MIVI& neighbors = graph_.constNeighbors();
    const MIS& decoder = mapper_.constCode2String();
    SHOW_MSVS_ENDL(cout, neighbors, decoder)
  }/* show */
  inline Graph& getGraph() {
    return graph_;
  }/* getGraph */
  inline const Graph& constGraph() const {
    return graph_;
  }/* constGraph */
  inline Mapper& getMapper() {
    return mapper_;
  }/* getMapper */
  inline const Mapper& constMapper() const {
  }/* constMapper */
};/* class Data */

}/* namespace TriangulationPlanarEmbedding*/
