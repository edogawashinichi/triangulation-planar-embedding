/* solver.h */

#pragma once

#include "../common/debug.h"
#include "../graph.h"
#include "../embedding.h"
#include "../config.h"

namespace TriangulationPlanarEmbedding {

class Solver {
public:
  virtual void run(const Graph& graph, const Config& config, Embedding* embedding) = 0;
};/* class Solver */

}/* namespace TriangulationPlanarEmbedding */
