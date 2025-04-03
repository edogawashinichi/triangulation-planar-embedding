/* test_solver.cxx */

#include "../../src/solver/ring_in_ring.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  RingResult result;
  INFO_OBJ(result)
  result.showStructure(std::cout);
  SHOW_VAR_ENDL(std::cout, result.size())
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
