/* graph_searcher.h */

/* assuming the graph is a 5-star-connected triangulation */
/* 5-star-connected: */
/*     firstly, 5-connected
       secondly, every 5 ring must be a 5 wheel */

/* every adjacent vertex pair has exactly 2 guards 
       proof: assuming 3 guards ==> at most 3-connected */

/* every triangle has exactly 3 guards 
       proof: assuming 2 guards ==> one vertex pair has 3 guards */

/* every 4-ring has exactly 4 guards */
/* every 5-ring has exactly 1 or 5 semi-guards */

/* a 6-ring may have exactly 1 or 2 or 3 or 4 or 5 or 6 semi-guards */

#pragma once

#include "../graph.h"
#include "../topology/complete_result.h"
#include "../common/notation.h"
#include "../solver/ring_in_ring.h"
#include "../solver/merged_ring_in_ring.h"

namespace TriangulationPlanarEmbedding {

class GraphSearcher {
SINGLETON_ASSERTION(GraphSearcher)
public:
  bool findCompleteSubgraph(const Graph& graph, const size_t subgraph_size, VI* vertices);
  bool findCompleteSubgraph(const Graph& graph, const size_t subgraph_size, const size_t vertex, VI* vertices);
protected:
  bool dfsCompleteSubgraph(const Graph& graph, const size_t subgraph_size, const VI& neighbors, const size_t index, VI* neighbor_stack);
public:
  bool findOutermostRing(const Graph& graph, RingInRing* ring, MergedRingInRing* merged_ring);
  bool findSubouterRing(const Graph& graph, const RingInRing& outermost_ring, RingInRing* subouter_ring, MergedRingInRing* merged_subouter_ring);
  void findInnerRing(const Graph& graph, const RingInRing& outer_ring, const RingInRing& ring, RingInRing* inner_ring, MergedRingInRing* merged_inner_ring);
public:
  bool findPathOfSize(const Graph& graph, const size_t size, const size_t start_vertex, const size_t end_vertex, VI* path);
protected:
  bool findPathOfSizeHelper(const Graph& graph, const size_t size, const size_t cur_vertex, const size_t end_vertex, VI* visited, VI* path);
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
