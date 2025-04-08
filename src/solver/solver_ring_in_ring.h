/* solver_ring_in_ring.h */

#pragma once

#include "solver.h"
#include "ring_in_ring.h"
#include "merged_ring_in_ring.h"

namespace TriangulationPlanarEmbedding {

class SolverRingInRing : public Solver {
SINGLETON_ASSERTION(SolverRingInRing)
public:
  virtual void run(const Graph& graph, const Config& config, Embedding* embedding) override;
protected:
  void findRingResult(const Graph& graph, RingResult* ring_result, MergedRingResult* merged_ring_result);
};/* class SolverRingInRing */

#define SOLVER_RING_IN_RING SolverRingInRing::getInstance()

}/* namespace TriangulationPlanarEmbedding */
