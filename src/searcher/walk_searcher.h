/* walk_searcher.h */

#pragma once

#include "../common/debug.h"
#include "../graph.h"
#include "../solver/closed_walk_tree/closed_walk_tree.h"
#include "../solver/walk_triangle/walk_guard.h"
#include "../solver/walk_triangle/walk_triangle.h"
#include "../solver/walk_triangle/guard_path.h"

namespace TriangulationPlanarEmbedding {

class WalkSearcher {
SINGLETON_ASSERTION(WalkSearcher)
public:
  bool findInnermostWalk(const Graph& graph, ClosedWalk* innermost_walk, Tree* tree);
  bool findSubinnerWalk(const Graph& graph, const ClosedWalk& innermost_walk, ClosedWalk* subinner_walk, Tree* tree, WalkGuardVector* guards, GuardPathVector* paths, WalkTriangleVector* triangles);
protected:
  bool setSubinnerWalk(const WalkGuardVector& guards, const GuardPathVector& paths, ClosedWalk* subinner_walk, Tree* tree, WalkTriangleVector* triangles);
  bool setInnermostWalk(const VI& vertices, ClosedWalk* innermost_walk, Tree* tree);
  bool findWalkGuards(const Graph& graph, const ClosedWalk& innermost_walk, WalkGuardVector* guards);
  bool findGuardPaths(const Graph& graph, const ClosedWalk& innermost_walk, const WalkGuardVector& guards, GuardPathVector* paths);
};/* class WalkSearcher */

#define WALK_SEARCHER WalkSearcher::getInstance()

}/* namespace TriangulationPlanarEmbedding */
