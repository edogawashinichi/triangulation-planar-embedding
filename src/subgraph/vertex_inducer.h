/* vertex_inducer.h */

#pragma once

#include "edge_inducer.h"

namespace TriangulationPlanarEmbedding {

class VertexInducer {
SINGLETON_ASSERTION(VertexInducer)
public:
  inline void run(const Graph& graph, const VI& vertices, Graph* subgraph) {
    DEBUG_START(VertexInducer::run)
    /* VII inducer_edges; */
    subgraph->clear();
    const VII& edges = graph.getEdges();
    const SI set(vertices.begin(), vertices.end());
    for (const auto& edge : edges) {
      const I u = edge.first;
      const I v = edge.second;
      if (!set.count(u) || !set.count(v)) continue;
      /* inducer_edges.emplace_back(PII({u, v})); */
      subgraph->addSymmetry(u, v);
    }/* for edge */
    /* EDGE_INDUCER.run(graph, inducer_edges, subgraph); */
    subgraph->setN(graph.n());
    DEBUG_END(VertexInducer::run)
  }/* run */
};/* class VertexInducer */

#define VERTEX_INDUCER VertexInducer::getInstance()

}/* namespace TriangulationPlanarEmbedding */
