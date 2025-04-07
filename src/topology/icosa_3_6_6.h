/* icosa_3_6_6.h */

#pragma once

#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class Icosa_3_6_6 : public Graph {
SINGLETON_ASSERTION_WITHOUT_PRIVATE(Icosa_3_6_6)
private:
  inline Icosa_3_6_6() : Graph() {
    Graph::setN(15);
    const VVI edges = {
      {0, 1}, {0, 2}, {0, 4}, {0, 5}, {0, 6},   /*5*/
      {1, 2}, {1, 6}, {1, 7}, {1, 8},           /*4*/
      {2, 3}, {2, 4}, {2, 8},                   /*3*/
      {3, 4}, {3, 8}, {3, 9}, {3, 10}, {3, 11}, /*5*/
      {4, 5}, {4, 11},                          /*2*/
      {5, 6}, {5, 11}, {5, 12}, {5, 13},        /*4*/
      {6, 7}, {6, 13},                          /*2*/
      {7, 8}, {7, 9}, {7, 13}, {7, 14},         /*4*/
      {8, 9},                                   /*1*/
      {9, 10}, {9, 14},                         /*2*/
      {10, 11}, {10, 12}, {10, 14},             /*3*/
      {11, 12},                                 /*1*/
      {12, 13}, {12, 14},                       /*2*/
      {13, 14}                                  /*1*/
    };/* edges */
    for (const auto& edge : edges) {
      Graph::addSymmetry(edge[0], edge[1]);
    }/* for */
  }/* constructor default */
public:
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    SHOW_ENDL(cout, "this is an icosa_3_6_6")
    Graph::show(cout);
  }/* show */
};/* class Icosa_3_6_6 */

#define ICOSA_3_6_6 Icosa_3_6_6::getInstance()

}/* namespace TriangulationPlanarEmbedding */
