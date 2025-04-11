/* tiler.h */

#pragma once

#include "../graph.h"
#include "../config.h"
#include "../solver/merged_ring_in_ring.h"
#include "../embedding.h"

namespace TriangulationPlanarEmbedding {

class Tiler {
public:
  virtual void run(const Graph& graph, const Config& config, const MergedRingResult& rings, Embedding* embedding) = 0;
};/* class Tiler */

}/* namespace TriangulationPlanarEmbedding */
