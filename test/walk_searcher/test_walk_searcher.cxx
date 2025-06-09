/* test_walk_searcher.cxx */

#include "../../src/searcher/walk_searcher.h"
#include "../../src/topology/icosahedron.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  const Graph& graph = ICOSAHEDRON;
  ClosedWalk innermost_walk;
  Tree tree;
  WALK_SEARCHER.findInnermostWalk(graph, &innermost_walk, &tree);
  INFO_OBJ(innermost_walk)
  INFO_OBJ(tree)
  ClosedWalk subinner_walk;
  WalkGuardVector guards;
  GuardPathVector paths;
  WalkTriangleVector triangles;
  WALK_SEARCHER.findSubinnerWalk(graph, innermost_walk, &subinner_walk, &tree, &guards, &paths, &triangles);
  INFO_OBJ(subinner_walk)
  INFO_OBJ(tree)
  INFO_OBJ(guards)
  INFO_OBJ(paths)
  INFO_OBJ(triangles)
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
