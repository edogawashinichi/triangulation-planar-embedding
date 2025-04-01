/* edge_inducer.h */

#pragma once

#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class EdgeInducer {
SINGLETON_ASSERTION(EdgeInducer)
public:
  inline void run(const Graph& graph, const VII& edges, Graph* subgraph) {
    DEBUG_START(EdgeInducer::run)
    subgraph->clear();
    subgraph->setN(graph.n());
    for (const auto& edge : edges) {
      const I u = edge.first;
      const I v = edge.second;
      if (!graph.containEdge(u, v)) continue;
      subgraph->addSymmetry(u, v);
    }/* for */
    DEBUG_END(EdgeInducer::run)
  }/* run */
};/* class EdgeInducer */

#define EDGE_INDUCER EdgeInducer::getInstance()

}/* namespace TriangulationPlanarEmbedding */
