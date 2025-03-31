/* graph_searcher.h */

#pragma once

#include "../graph.h"
#include "../topology/complete_three.h"
#include "../common/notation.h"

namespace TriangulationPlanarEmbedding {

class GraphSearcher {
SINGLETON_ASSERTION(GraphSearcher)
public:
  bool findCompleteThree(const Graph& graph, CompleteThreeResult* ring);
  bool findInnerRing(const Graph& graph, const CompleteThreeResult& ring, Ring* inner_ring);
  bool findInnerRing(const Graph& graph, const Ring& outer_ring, const Ring& ring, Ring* inner_ring);
};/* class GraphSearcher */

#define GRAPH_SEARCHER GraphSearcher::getInstance()

}/* namespace TriangulationPlanarEmbedding */
