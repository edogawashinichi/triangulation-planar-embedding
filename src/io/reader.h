/* reader.h */

#pragma once

#include "../common/notation.h"
#include "../graph.h"
#include "../config.h"

namespace TriangulationPlanarEmbedding {

class Reader {
SINGLETON_ASSERTION(Reader)
public:
  bool readGraph(const std::string& file, Graph* graph);
  bool readConfig(const std::string& file, Config* config);
};/* class Reader */

#define READER Reader::getInstance()

}/* namespace TriangulationPlanarEmbedding */
