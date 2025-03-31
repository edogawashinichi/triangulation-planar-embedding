/* graph_searcher.cxx */

#include "graph_searcher.h"
#include "../common/math.h"

namespace TriangulationPlanarEmbedding {

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
  bool res = false;
  inner_ring->vertices_.clear();
  const VVI& pairs = {
    {ring.U(), ring.V()}, {ring.V(), ring.W()}, {ring.W(), ring.U()}
  };
  VI guards_in_order;
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
  for (const I v : guards_in_order) {
  }/*  */
  DEBUG_VI(guards_in_order)
  DEBUG_END(findInnerRing)
  return res;
}/* GraphSearcher::findInnerRing */

bool GraphSearcher::findInnerRing(const Graph& graph, const Ring& outer_ring, const Ring& ring, Ring* inner_ring) {
  return true;
}/* GraphSearcher::findInnerRing */

}/* namespace TriangulationPlanarEmbedding */
