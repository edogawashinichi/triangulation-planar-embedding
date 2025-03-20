/* graph.h */

/*
   undirected
   simple: no loops, no multi-edges
*/

#pragma once

#include "common/notation.h"

namespace TriangulationPlanarEmbedding {

class Graph {
CLASS_5_FUNCTIONS(Graph, n_, neighbors_)
public:
protected:
  I n_;/* number of vertices */
  VVI neighbors_;
};/* class Graph */

}/* namespace TriangulationPlanarEmbedding */
