/* graph_searcher.h */

#pragma once

#include "../graph.h"
#include "../topology/complete_three.h"
#include "../common/notation.h"

namespace TriangulationPlanarEmbedding {

class GraphSearcher {
SINGLETON_ASSERTION(GraphSearcher)
public:
  bool findRingPath(const Graph& graph, const VI& vertices, const I start_vertex, const I end_vertex, VI* path);
protected:
  bool findRingPathHelper(const Graph& graph, const VI& vertices, const I cur_vertex, const I end_vertex, VI* visited, VI* path);
public:
  bool findCompleteThree(const Graph& graph, CompleteThreeResult* ring);
  bool findInnerRing(const Graph& graph, const CompleteThreeResult& ring, Ring* inner_ring);
  bool findInnerRingHelper(const Graph& graph, const CompleteThreeResult& ring, const VI& guards, Ring* inner_ring);
  bool findInnerRing(const Graph& graph, const Ring& outer_ring, const Ring& ring, Ring* inner_ring);
};/* class GraphSearcher */

#define GRAPH_SEARCHER GraphSearcher::getInstance()

}/* namespace TriangulationPlanarEmbedding */
