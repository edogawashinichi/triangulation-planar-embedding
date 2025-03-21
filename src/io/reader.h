/* reader.h */

#pragma once

#include "../common/notation.h"
#include "../config.h"
#include "../mapper.h"
#include "../graph.h"

namespace TriangulationPlanarEmbedding {

class Reader {
SINGLETON_ASSERTION(Reader)
public:
  bool readConfig(const std::string& file, Config* config);
  bool readGraph(const std::string& file, Mapper* mapper, Graph* graph);
};/* class Reader */

#define READER Reader::getInstance()

}/* namespace TriangulationPlanarEmbedding */
