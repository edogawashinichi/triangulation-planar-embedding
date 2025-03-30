/* test_graph_searcher.cxx */

#include "../../src/searcher/graph_searcher.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  CompleteGraph<4> k4;
  CompleteThreeResult result;
  GRAPH_SEARCHER.findCompleteThree(k4, &result);
  DEBUG_OBJ(result)
  const I u = result.u_;
  const I v = result.v_;
  const I w = result.w_;
  res = res && k4.containEdge(u, v);
  res = res && k4.containEdge(v, w);
  res = res && k4.containEdge(w, u);
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
