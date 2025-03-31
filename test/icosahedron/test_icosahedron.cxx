/* test_icosaheron.cxx */

#include "../../src/topology/icosahedron.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  INFO_OBJ(ICOSAHEDRON)
  res = res && (12 == ICOSAHEDRON.n());
  res = res && (30 == ICOSAHEDRON.m());
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
