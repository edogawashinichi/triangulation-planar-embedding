/* test_complete_graph.cxx */

#include "../../src/topology/complete_graph.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  CompleteGraph<4> K4;
  INFO_OBJ(K4)
TEST_END(0)

TEST_START(1)
  CompleteThree K3;
  DEBUG_OBJ(K3)
TEST_END(1)

MAIN_START
  TEST(0)
  TEST(1)
MAIN_END
