/* graph_searcher.cxx */

#include "graph_searcher.h"
#include "../common/math.h"
#include "../subgraph/vertex_inducer.h"

/* TODO: debug DEBUG_VAR_ENDL */

namespace TriangulationPlanarEmbedding {

bool GraphSearcher::findRingPath(const Graph& graph, const VI& vertices, const I start_vertex, const I end_vertex, VI* path) {
  DEBUG_START(findRingPath)
  VI visited(graph.n(), 0);
  visited[start_vertex] = 1;
  path->emplace_back(start_vertex);
  bool res = this->findRingPathHelper(graph, vertices, start_vertex, end_vertex, &visited, path);
  DEBUG_END(findRingPath)
  return res;
}/* GraphSearcher::findRingPath */

bool GraphSearcher::findRingPathHelper(const Graph& graph, const VI& vertices, const I cur_vertex, const I end_vertex, VI* visited, VI* path) {
  DEBUG_START(findRingPathHelper)
  /*SHOW_VAR_ENDL(cur_vertex, end_vertex)*/
  if (cur_vertex == end_vertex) {
    /*SHOW_VAR_ENDL(cur_vertex, end_vertex)*/
    DEBUG_END(findRingPathHelper)
    return path->size() == vertices.size();  
  }/* if */
  bool res = false;
  for (const I& v : graph.neighbors(cur_vertex)) {
    if ((*visited)[v]) continue;
    (*visited)[v] = 1;
    path->emplace_back(v);
    if (this->findRingPathHelper(graph, vertices, v, end_vertex, visited, path)) {
      res = true;
      break;
    }/* if */
    (*visited)[v] = 0;
    path->pop_back();
  }/* for */
  /*SHOW_VAR_ENDL(cur_vertex, end_vertex)*/
  DEBUG_END(findRingPathHelper)
  return res;
}/* GraphSearcher::findRingPathHelper */

bool GraphSearcher::findCompleteThree(const Graph& graph, CompleteThreeResult* ring) {
  DEBUG_START(findCompleteThree)
  ring->clear();
  bool res = false;
  for (size_t u = 0; u < graph.n(); ++u) {
    for (size_t v : graph.neighbors(u)) {
      for (size_t w : graph.neighbors(v)) {
        if (!graph.containEdge(u, w)) continue;
        ring->set(u, v, w);
        res = true;
        break;
      }/* for w */
      if (res) break;
    }/* for v */
    if (res) break;
  }/* for u */
  DEBUG_END(findCompleteThree)
  return res;
}/* GraphSearcher::findCompleteThree */

bool GraphSearcher::findInnerRing(const Graph& graph, const CompleteThreeResult& ring, Ring* inner_ring) {
  DEBUG_START(findInnerRing)

  /* find guards */
  VI guards_in_order;
  const VVI& pairs = {
    {ring.U(), ring.V()}, {ring.V(), ring.W()}, {ring.W(), ring.U()}
  };
  for (const auto& pair : pairs) {
    const I a = pair[0];
    const I b = pair[1];
    SI common_neighbors;
    cap<I>(graph.neighbors(a), graph.neighbors(b), &common_neighbors);
    SI guards;
    diff<I>(common_neighbors, {ring.U(), ring.V(), ring.W()}, &guards);
    for (const I guard : guards) {
      no_duplicate_add<I>(guard, &guards_in_order);
      break;/* planar graph ==> |guards|=1 */
    }/* for guard */
  }/* for pair */
  DEBUG_VI(guards_in_order)

  bool res = this->findInnerRingHelper(graph, ring, guards_in_order, inner_ring);
  DEBUG_END(findInnerRing)
  return res;
}/* GraphSearcher::findInnerRing */

bool GraphSearcher::findInnerRingHelper(const Graph& graph, const CompleteThreeResult& ring, const VI& guards, Ring* inner_ring) {
  DEBUG_START(findInnerRingHelper)
  inner_ring->clear();
  const int n = guards.size();
  for (int i = 0; i < n; ++i) {
    const I a = guards[i % n];
    const I b = guards[(i + 1) % n];
    /*SHOW_VAR_ENDL(a, b)*/
    VI common_neighbors;
    cap<I>(graph.neighbors(a), graph.neighbors(b), &common_neighbors);
    VI common_on_ring;
    cap<I>(common_neighbors, ring.vertices_, &common_on_ring);/* planar graph ==> |common_on_ring|=1 */
    VI inner_vertices;
    diff<I>(graph.neighbors(common_on_ring[0]), ring.vertices_, &inner_vertices);
    Graph subgraph;
    VERTEX_INDUCER.run(graph, inner_vertices, &subgraph);
    VI path;
    this->findRingPath(subgraph, inner_vertices, a, b, &path);
    DEBUG_VI(path)
    inner_ring->addExceptLast(path);
    DEBUG_OBJ(*inner_ring)
  }/* for */
  DEBUG_END(findInnerRingHelper)
  return inner_ring->vertices_.size() > 0;
}/* GraphSearcher::findInnerRingHelper */

bool GraphSearcher::findInnerRing(const Graph& graph, const Ring& outer_ring, const Ring& ring, Ring* inner_ring) {
  return true;
}/* GraphSearcher::findInnerRing */

}/* namespace TriangulationPlanarEmbedding */
