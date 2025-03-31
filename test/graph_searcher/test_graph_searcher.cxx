/* test_graph_searcher.cxx */

#include "../../src/searcher/graph_searcher.h"
#include "../../src/topology/icosahedron.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  CompleteGraph<4> k4;
  CompleteThreeResult result;
  GRAPH_SEARCHER.findCompleteThree(k4, &result);
  DEBUG_OBJ(result)
  const I u = result.U();
  const I v = result.V();
  const I w = result.W();
  res = res && k4.containEdge(u, v);
  res = res && k4.containEdge(v, w);
  res = res && k4.containEdge(w, u);
TEST_END(0)

TEST_START(1)
  CompleteThreeResult k3;
  GRAPH_SEARCHER.findCompleteThree(ICOSAHEDRON, &k3);
  DEBUG_OBJ(k3)
  Ring ring;
  GRAPH_SEARCHER.findInnerRing(ICOSAHEDRON, k3, &ring);
  DEBUG_OBJ(ring)
TEST_END(1)

MAIN_START
  TEST(0)
  TEST(1)
MAIN_END
