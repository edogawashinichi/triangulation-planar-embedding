/* walk_searcher.cxx */

#include "walk_searcher.h"
#include "graph_searcher.h"
#include "../subgraph/vertex_inducer.h"

/* TODO: transform innermost-K3-ClosedWalkTree to innermost-K2-ClosestWalkTree or innermost-K1-ClosestWalkTree */

namespace TriangulationPlanarEmbedding {

bool WalkSearcher::findInnermostWalk(const Graph& graph, ClosedWalk* innermost_walk, Tree* tree) {
  DEBUG_START(WalkSearcher::findInnermostWalk)
  /* find random K3 */
  VI vertices;
  bool res = GRAPH_SEARCHER.findCompleteSubgraph(graph, 3, &vertices);
  res = res && this->setInnermostWalk(vertices, innermost_walk, tree);
  DEBUG_END(WalkSearcher::findInnermostWalk)
  return res;
}/* WalkSearcher::findInnermostRing */

bool WalkSearcher::setInnermostWalk(const VI& vertices, ClosedWalk* innermost_walk, Tree* tree) {
  innermost_walk->set(vertices);
  tree->setRoot();
  return true;
}/* WalkSearcher::setInnermostWalk */

bool WalkSearcher::findSubinnerWalk(const Graph& graph, const ClosedWalk& innermost_walk, ClosedWalk* subinner_walk, Tree* tree, WalkGuardVector* guards, GuardPathVector* paths, WalkTriangleVector* triangles) {
  DEBUG_START(WalkSearcher::findSubinnerWalk)
  bool res = this->findWalkGuards(graph, innermost_walk, guards);
  res = res && this->findGuardPaths(graph, innermost_walk, *guards, paths);
  res = res && this->setSubinnerWalk(*guards, *paths, subinner_walk, tree, triangles);
  DEBUG_END(WalkSearcher::findSubinnerWalk)
  return res;
}/* WalkSearcher::findSubinnerWalk */

bool WalkSearcher::setSubinnerWalk(const WalkGuardVector& guards, const GuardPathVector& paths, ClosedWalk* subinner_walk, Tree* tree, WalkTriangleVector* triangles) {
  /* subinner_walk */
  subinner_walk->clear();
  for (size_t i = 0; i < paths.size(); ++i) {
    /* WARNING: don't copy data unless unavoidable */
    const GuardPath& path = paths.getConst(i);
    for (size_t j = 0; j < path.size() - 1; ++j) {
      subinner_walk->add(path.constCitizen(j).constVertex());
    }/* for j */
  }/* for i */

  /* tree */
  tree->setSubroot();

  /* triangles */
  triangles->clear();
  for (size_t i = 0; i < paths.size(); ++i) {
    const GuardPath& path = paths.getConst(i);
    const GuardNode& guard_start = path.constGuardStart();
    const size_t& u = guard_start.constVertex();
    const size_t& v = guard_start.constParent();
    const size_t& w = guard_start.constQarent();
    triangles->add(CompleteThreeResult(u, v, w));
    for (size_t j = 0; j < path.size() - 1; ++j) {
      const size_t& a = path.constCitizen(j).constVertex();
      const size_t& b = path.constCitizen(j + 1).constVertex();
      const size_t& c = path.constCitizen(j).constParent();
      triangles->add(CompleteThreeResult(a, b, c));
    }/* for j */
  }/* for i */

  return true;
}/* WalkSearcher::setSubinnerWalk */

bool WalkSearcher::findGuardPaths(const Graph& graph, const ClosedWalk& innermost_walk, const WalkGuardVector& guards, GuardPathVector* paths) {
  DEBUG_START(WalkSearcher::findGuardPaths)
  paths->clear();
  const int n = static_cast<int>(guards.size());
  /* innermost_walk.size == guards.size */
  for (int i = 0; i < n; ++i) {
    const int j = (i + 1) % n;
    const GuardNode& guard_u = guards.getConst(i);
    const GuardNode& guard_v = guards.getConst(j);
    const size_t u = guard_u.constVertex();
    const size_t v = guard_v.constVertex();
    const size_t w = innermost_walk.getConst(j);/* common parent of u,v */
    VI path_vertices;
    diff<size_t>(graph.neighbors(w), innermost_walk.getConst(), &path_vertices);
    Graph subgraph;
    VERTEX_INDUCER.run(graph, path_vertices, &subgraph);
    VI path;
    const size_t size = path_vertices.size();
    GRAPH_SEARCHER.findPathOfSize(subgraph, size, u, v, &path);
    paths->add(guard_u, guard_v, w, path);
  }/* for */
  DEBUG_END(WalkSearcher::findGuardPaths)
  return !paths->empty();
}/* WalkSearcher::findGuardPaths */

bool WalkSearcher::findWalkGuards(const Graph& graph, const ClosedWalk& innermost_walk, WalkGuardVector* guards) {
  /* assuming innermost_walk size >= 2 */
  DEBUG_START(WalkSearcher::findWalkGuards)
  guards->clear();
  const VI& vertices = innermost_walk.getConst();
  const int n = static_cast<int>(vertices.size());
  for (int i = 0; i < n; ++i) {
    const int j = (i + 1) % n;
    const size_t u = vertices[i];
    const size_t v = vertices[j];
    VI common_neighbors;
    cap<size_t>(graph.neighbors(u), graph.neighbors(v), &common_neighbors);
    VI common_neighbors_on_subinner;
    diff<size_t>(common_neighbors, vertices, &common_neighbors_on_subinner);
    guards->add(common_neighbors_on_subinner.front(), u, v);/* |common_neighbors_on_subinner|==1 */
  }/* for */
  DEBUG_END(WalkSearcher::findWalkGuards)
  return !guards->empty();
}/* WalkSearcher::findWalkGuards */

}/* namespace TriangulationPlanarEmbedding */
