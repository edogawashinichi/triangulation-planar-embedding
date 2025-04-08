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
  INFO_OBJ(k3)
  Ring ring;
  GRAPH_SEARCHER.findInnerRing(ICOSAHEDRON, k3, &ring);
  INFO_OBJ(ring)
TEST_END(1)

TEST_START(2)
  RingInRing outermost_ring;
  MergedRingInRing merged_outermost_ring;
  GRAPH_SEARCHER.findOutermostRing(ICOSAHEDRON, &outermost_ring, &merged_outermost_ring);
  INFO_OBJ(outermost_ring)
  INFO_OBJ(merged_outermost_ring)
TEST_END(2)

TEST_START(3)
  RingInRing outermost_ring;
  MergedRingInRing merged_outermost_ring;
  GRAPH_SEARCHER.findOutermostRing(ICOSAHEDRON, &outermost_ring, &merged_outermost_ring);
  DEBUG_OBJ(outermost_ring)
  DEBUG_OBJ(merged_outermost_ring)
  RingInRing subouter_ring;
  MergedRingInRing merged_subouter_ring;
  GRAPH_SEARCHER.findSubouterRing(ICOSAHEDRON, outermost_ring, &subouter_ring, &merged_subouter_ring);
  INFO_OBJ(subouter_ring)
  INFO_OBJ(merged_subouter_ring)
TEST_END(3)

TEST_START(4)
  const Graph& graph = ICOSAHEDRON;
  RingInRing outermost_ring;
  MergedRingInRing merged_outermost_ring;
  GRAPH_SEARCHER.findOutermostRing(graph, &outermost_ring, &merged_outermost_ring);
  VERBOSE_OBJ(outermost_ring)
  VERBOSE_OBJ(merged_outermost_ring)
  RingInRing subouter_ring;
  MergedRingInRing merged_subouter_ring;
  GRAPH_SEARCHER.findSubouterRing(graph, outermost_ring, &subouter_ring, &merged_subouter_ring);
  VERBOSE_OBJ(subouter_ring)
  VERBOSE_OBJ(merged_subouter_ring)
  RingInRing next_ring;
  MergedRingInRing merged_next_ring;
  GRAPH_SEARCHER.findInnerRing(graph, outermost_ring, subouter_ring, &next_ring, &merged_next_ring);
  INFO_OBJ(next_ring)
  INFO_OBJ(merged_next_ring)
TEST_END(4)

MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
  TEST(4)
MAIN_END
