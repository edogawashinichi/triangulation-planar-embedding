/* graph_searcher.cxx */

#include "graph_searcher.h"
#include "../common/math.h"
#include "../subgraph/vertex_inducer.h"
#include "../solver/ring_in_ring_trimmer.h"

/* TODO: debug DEBUG_VAR_ENDL */

namespace TriangulationPlanarEmbedding {

bool GraphSearcher::findOutermostRing(const Graph& graph, RingInRing* ring, MergedRingInRing* merged_ring) {
  /* ring must be 3-ring */
  DEBUG_START(findOutermostRing)
  ring->clear();
  merged_ring->clear();

  CompleteThreeResult result;
  bool res = this->findCompleteThree(graph, &result);
  ring->add(result.vertices_);
  merged_ring->add(result.vertices_);

  DEBUG_END(findOutermostRing)
  return res;
}/* GraphSearcher::findOutermostRing */

bool GraphSearcher::findSubouterRing(const Graph& graph, const RingInRing& outermost_ring, RingInRing* subouter_ring, MergedRingInRing* merged_subouter_ring) {
  /* outermost_ring has exactly 3 guards on subouter_ring */
  DEBUG_START(findSubouterRing)
  subouter_ring->clear();
  merged_subouter_ring->clear();

  /* find the 3 guards */
  VI guards;
  const VI& vertices = outermost_ring.getVertices();
  const int n = vertices.size();/* n==3 */
  for (int i = 0; i < n; ++i) {
    const I u = vertices[i];
    const I v = vertices[(i + 1) % n];
    VI common_neighbors;
    cap<I>(graph.neighbors(u), graph.neighbors(v), &common_neighbors);
    VI guards_on_subouter;
    diff<I>(common_neighbors, vertices, &guards_on_subouter);/* |guards_on_subouter|==1 */
    guards.emplace_back(guards_on_subouter.front());
  }/* for */

  /* find the subouter_ring path between each guard pair */
  const int k = guards.size();/* k==n==3 */
  for (int i = 0; i < k; ++i) {
    const I next_i = (i + 1) % k;
    const I a = guards[i];
    const I b = guards[next_i];
    VI common_neighbors;
    cap<I>(graph.neighbors(a), graph.neighbors(b), &common_neighbors);/* |common_neighbors|==2 */
    VI neighbors_on_outermost;
    cap<I>(common_neighbors, vertices, &neighbors_on_outermost);/* |neighbors_on_outermost|==1 */
    const I c = neighbors_on_outermost.front();
    VI neighbors_on_subouter;
    diff<I>(graph.neighbors(c), vertices, &neighbors_on_subouter);
    Graph subgraph;
    VERTEX_INDUCER.run(graph, neighbors_on_subouter, &subgraph);
    VI path;
    this->findRingPath(subgraph, neighbors_on_subouter, a, b, &path);
    DEBUG_VI(path)
    subouter_ring->add(a, vertices[i], vertices[next_i], i, next_i);
    merged_subouter_ring->add(a, vertices[i], vertices[next_i], i, next_i);
    for (int j = 1; j < path.size() - 1; ++j) {
      subouter_ring->add(path[j]);
      merged_subouter_ring->add(path[j]);
    }/* for j */
  }/* for i */
  DEBUG_END(findSubouterRing)
  return subouter_ring->size() > 0;
}/* GraphSearcher::findSubouterRing */

void GraphSearcher::findInnerRing(const Graph& graph, const RingInRing& outer_ring, const RingInRing& ring, RingInRing* inner_ring, MergedRingInRing* merged_inner_ring) {
  /* the outermost ring must be a 3-ring */
  /* the guards on the subouter ring must be 3 distinct vertices */
  /*     the subouter ring must have no duplicate */
  /* the guards on the rest rings may have duplicate */
  /*     so the rings are represented as walks */
  /* once the guards on a inner ring have none adjacent duplicate */
  /*     the next ring may not be connected */
  /* currently we deal with the next ring as if it's connected */

  DEBUG_START(GraphSearcher::findInnerRing)
  inner_ring->clear();
  merged_inner_ring->clear();
  
  /* find ring's guards on inner_ring */
  /* these guards may have duplicate (adjacent or non-adjacent) */

  /* WARNING: parents information is required*/
  RingInRing guards_on_inner_ring;/* raw guards */
  const VI& ring_vertices = ring.getVertices();
  const int n = ring_vertices.size();
  for (int i = 0; i < n; ++i) {
    const I next_i = (i + 1) % n;
    const I u = ring_vertices[i];
    const I v = ring_vertices[next_i];
    VI common_neighbors;
    cap<I>(graph.neighbors(u), graph.neighbors(v), &common_neighbors);/* |common_neighbors|==2 */
    VI neighbors_excluding_outer;
    diff<I>(common_neighbors, outer_ring.getVertices(), &neighbors_excluding_outer);
    /* |neighbors_excluding_outer|==0 if duplicate edge on ring
       |neighbors_excluding_outer|==1 otherwise */
    VI neighbors_on_inner;
    diff<I>(neighbors_excluding_outer, ring_vertices, &neighbors_on_inner);
    /* |neighbors_on_inner|==0 if both of common_neighbors on outer_ring or one on outer_ring the other on ring 
       |neighbors_on_inner|==1 otherwise */
    if (neighbors_on_inner.empty()) continue;
    const I w = neighbors_on_inner.front();
    guards_on_inner_ring.add(w, u, v, i, next_i);
  }/* for */
  DEBUG_OBJ(guards_on_inner_ring)
  RingInRing trimmed_guards_on_inner_ring;
  RING_IN_RING_TRIMMER.run(guards_on_inner_ring, &trimmed_guards_on_inner_ring);
  DEBUG_OBJ(trimmed_guards_on_inner_ring)

  /* find the inner_ring path between each guard pair */
  /* WARNING: directly travese guards_on_inner_ring */
  /*          to make use of common parent */
  const auto& guards = guards_on_inner_ring;/* may have adjacent/non-adjacent duplicate */
  const int k = guards.size();
  for (int j = 0; j < k; ++j) {
    const I a = guards.getConst(j).getVertex();
    const I next_j = (j + 1) % k;
    const I b = guards.getConst(next_j).getVertex();
    if (a == b) {
      merged_inner_ring->add(guards.getConst(j));
      continue;
    }/* if */ 
    VI common_parent;
    cap<I>(guards.getConst(j).getParentsVector(), guards.getConst(next_j).getParentsVector(), &common_parent);
    DEBUG_VI(common_parent)
    const I c = common_parent.front(); /* |common_parent|==1 */
    VI neighbors_excluding_outer;
    diff<I>(graph.neighbors(c), outer_ring.getVertices(), &neighbors_excluding_outer);
    VI neighbors_on_inner;
    diff<I>(neighbors_excluding_outer, ring_vertices, &neighbors_on_inner);/* |neighbors_on_inner|>=2 */
    Graph subgraph;
    VERTEX_INDUCER.run(graph, neighbors_on_inner, &subgraph);
    VI path;
    this->findRingPath(subgraph, neighbors_on_inner, a, b, &path);
    DEBUG_VI(path)
    inner_ring->add(guards.getConst(j));
    merged_inner_ring->add(guards.getConst(j));
    for (size_t index = 1; index < path.size() - 1; ++index) {
      inner_ring->add(path[index]);
      merged_inner_ring->add(path[index]);
    }/* for path */
  }/* for guards */

  DEBUG_END(GraphSearcher::findInnerRing)
}/* GraphSearcher::findInnerRing */

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
