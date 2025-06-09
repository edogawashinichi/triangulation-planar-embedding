/* test_complete_graph.cxx */

#include "../../src/topology/complete_graph.h"
#include "../../src/topology/complete_result.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  CompleteGraph<4> K4;
  INFO_OBJ(K4)
  res = res && (4 == K4.n());
TEST_END(0)

TEST_START(1)
  CompleteThree K3;
  DEBUG_OBJ(K3)
  res = res && (3 == K3.n());
TEST_END(1)

TEST_START(2)
  CompleteThreeResult result;
  VERBOSE_OBJ(result)
TEST_END(2)

MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
MAIN_END
