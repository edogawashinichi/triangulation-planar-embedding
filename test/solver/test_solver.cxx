/* test_solver.cxx */

#include "../../src/solver/ring_in_ring.h"
#include "../../src/solver/solver_ring_in_ring.h"
#include "../../src/topology/icosahedron.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  RingResult result;
  INFO_OBJ(result)
  result.showStructure(std::cout);
  SHOW_VAR_ENDL(std::cout, result.size())
TEST_END(0)

TEST_START(1)
  const Graph& graph = ICOSAHEDRON;
  Config config;
  Embedding embedding;
  SOLVER_RING_IN_RING.run(graph, config, &embedding);
  INFO_OBJ(embedding)
TEST_END(1)

MAIN_START
  TEST(0)
  TEST(1)
MAIN_END
