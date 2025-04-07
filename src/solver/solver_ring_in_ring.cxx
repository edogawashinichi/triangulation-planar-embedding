/* solver_ring_in_ring.cxx */

#include "solver_ring_in_ring.h"
#include "../searcher/graph_searcher.h"

namespace TriangulationPlanarEmbedding {

void SolverRingInRing::run(const Graph& graph, const Config& config, Embedding* embedding) {
  DEBUG_START(SolverRingInRing::run)
  RingResult ring_result;
  this->findRingResult(graph, &ring_result);
  DEBUG_OBJ(ring_result)
  ring_result.showStructure(std::cout);
  DEBUG_END(SolverRingInRing::run)
}/* SolverRingInRing::run */

void SolverRingInRing::findRingResult(const Graph& graph, RingResult* ring_result) {
  DEBUG_START(SolverRingInRing::findRingResult)
  RingInRing outermost_ring;
  GRAPH_SEARCHER.findOutermostRing(graph, &outermost_ring);
  DEBUG_OBJ(outermost_ring)
  RingInRing subouter_ring;
  GRAPH_SEARCHER.findSubouterRing(graph, outermost_ring, &subouter_ring);
  DEBUG_OBJ(subouter_ring)
  ring_result->add(outermost_ring);
  ring_result->add(subouter_ring);
  VI unvisited_vertices(id<I>(graph.n()));
  diff<I>(&unvisited_vertices, outermost_ring.getVertices());
  diff<I>(&unvisited_vertices, subouter_ring.getVertices());
  for (size_t i = 2; true; ++i) {
    const RingInRing& outer_ring = ring_result->getConst(i - 2);
    const RingInRing& ring = ring_result->getConst(i - 1);
    RingInRing inner_ring;
    GRAPH_SEARCHER.findInnerRing(graph, outer_ring, ring, &inner_ring);
    ring_result->add(inner_ring);
    diff<I>(&unvisited_vertices, inner_ring.getVertices());
    SHOW_VAR_ENDL(std::cout, i)
    DEBUG_OBJ(inner_ring)
    DEBUG_VI(unvisited_vertices)
    if (unvisited_vertices.empty()) break;
  }/* while */
  DEBUG_END(SolverRingInRing::findRingResult)
}/* SolverRingInRing::findRingResult */

}/* namespace TriangulationPlanarEmbedding */
