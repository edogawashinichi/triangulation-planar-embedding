/* test_icosaheron.cxx */

#include "../../src/topology/icosahedron.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  Icosahedron IC;
  INFO_OBJ(IC)
  res = res && (12 == IC.n());
  res = res && (30 == IC.m());
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
