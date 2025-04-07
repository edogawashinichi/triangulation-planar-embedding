/* icosahedron.h */

#pragma once

#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class Icosahedron : public Graph {
SINGLETON_ASSERTION_WITHOUT_PRIVATE(Icosahedron)
private:
  inline Icosahedron() : Graph() {
    Graph::setN(12);
    const VVI edges = {
      {0, 1}, {0, 2}, {0, 4}, {0, 5}, {0, 6},
      {1, 2}, {1, 6}, {1, 7}, {1, 8},
      {2, 3}, {2, 4}, {2, 8},
      {3, 4}, {3, 8}, {3, 9}, {3, 10},
      {4, 5}, {4, 10},
      {5, 6}, {5, 10}, {5, 11},
      {6, 7}, {6, 11},
      {7, 8}, {7, 9}, {7, 11},
      {8, 9},
      {9, 10}, {9, 11},
      {10, 11}
    };/* edges */
    for (const auto& edge : edges) {
      Graph::addSymmetry(edge[0], edge[1]);
    }/* for */
  }/* constructor default */
public:
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    SHOW_ENDL(cout, "this is an icosahedron")
    Graph::show(cout);
  }/* show */
};/* class Icosahedron */

#define ICOSAHEDRON Icosahedron::getInstance()

#define ICOSA_3_6_3 ICOSAHEDRON

}/* namespace TriangulationPlanarEmbedding */
