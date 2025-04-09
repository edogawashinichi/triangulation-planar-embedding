/* birk_2_6_4.h */

#pragma once

#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class Birk_2_6_4 : public Graph {
SINGLETON_ASSERTION_WITHOUT_PRIVATE(Birk_2_6_4)
private:
  inline Birk_2_6_4() : Graph() {
    Graph::setN(12);
    const VVI edges = {
      {0, 1}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, /*5*/
      {1, 2}, {1, 3}, {1, 6}, {1, 7},         /*4*/
      {2, 3}, {2, 7}, {2, 8}, {2, 9},         /*4*/
      {3, 4}, {3, 9},                         /*2*/
      {4, 5}, {4, 9}, {4,10},                 /*3*/
      {5, 6}, {5, 10}, {5, 11},               /*3*/
      {6, 7}, {6, 11},                        /*2*/
      {7, 8}, {7, 11},                        /*2*/
      {8, 9}, {8, 10}, {8, 11},               /*3*/
      {9, 10},                                /*1*/
      {10, 11}                                /*1*/
    };/* edges */
    for (const auto& edge : edges) {
      Graph::addSymmetry(edge[0], edge[1]);
    }/* for */
  }/* constructor default */
public:
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    SHOW_ENDL(cout, "this is a birk_2_6_4")
    Graph::show(cout);
  }/* show */
};/* class Birk_2_6_4 */

#define BIRK_2_6_4 Icosa_2_6_4::getInstance()

}/* namespace TriangulationPlanarEmbedding */
