/* test_tree.cxx */

#include "../../src/common/tree.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  Tree tree;
  INFO_OBJ(tree)
TEST_END(0)

TEST_START(1)
  Tree tree;
  tree.setSize(5);
  const VVI& data = {
    {0, 1}, {1, 2}, {1, 3}, {1, 4}
  };
  for (const auto& pair : data) {
    const auto& u = pair[0];
    const auto& v = pair[1];
    tree.add(u, v);
  }/* for */
  INFO_OBJ(tree)
TEST_END(1)

MAIN_START
  TEST(0)
  TEST(1)
MAIN_END
