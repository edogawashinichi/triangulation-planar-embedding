/* graph_searcher.cxx */

#include "graph_searcher.h"

namespace TriangulationPlanarEmbedding {

bool GraphSearcher::findCompleteThree(const Graph& graph, CompleteThreeResult* result) {
  DEBUG_START(findCompleteThree)
  result->clear();
  bool res = false;
  for (size_t u = 0; u < graph.n(); ++u) {
    for (size_t v : graph.neighbors(u)) {
      for (size_t w : graph.neighbors(v)) {
        if (!graph.containEdge(u, w)) continue;
        result->set(u, v, w);
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

}/* namespace TriangulationPlanarEmbedding */
