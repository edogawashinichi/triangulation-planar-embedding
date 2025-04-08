/* icosa_3_7_4.h */

#pragma once

#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class Icosa_3_7_4 : public Graph {
SINGLETON_ASSERTION_WITHOUT_PRIVATE(Icosa_3_7_4)
private:
  inline Icosa_3_7_4() : Graph() {
    Graph::setN(14);
    const VVI edges = {
      {0, 1}, {0, 2}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, /*6*/
      {1, 2}, {1, 7}, {1, 8}, {1, 9},                 /*4*/
      {2, 3}, {2, 4}, {2, 9},                         /*3*/
      {3, 4}, {3, 9}, {3, 10}, {3, 11},               /*4*/
      {4, 5}, {4, 11},                                /*2*/
      {5, 6}, {5, 11}, {5, 12},                       /*3*/
      {6, 7}, {6, 12}, {6, 13},                       /*3*/
      {7, 8}, {7, 13},                                /*2*/
      {8, 9}, {8, 10}, {8, 13},                       /*3*/
      {9, 10},                                        /*1*/
      {10, 11}, {10, 12}, {10, 13},                   /*3*/
      {11, 12},                                       /*1*/
      {12, 13},                                       /*1*/
    };/* edges */
    for (const auto& edge : edges) {
      Graph::addSymmetry(edge[0], edge[1]);
    }/* for */
  }/* constructor default */
public:
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    SHOW_ENDL(cout, "this is an icosa_3_7_4")
    Graph::show(cout);
  }/* show */
};/* class Icosa_3_7_4 */

#define ICOSA_3_7_4 Icosa_3_7_4::getInstance()

}/* namespace TriangulationPlanarEmbedding */
