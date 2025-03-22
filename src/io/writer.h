/* writer.h */

#pragma once

#include "../common/notation.h"
#include "../embedding.h"
#include "../mapper.h"

namespace TriangulationPlanarEmbedding {

class Writer {
SINGLETON_ASSERTION(Writer)
public:
  bool writeEmbedding(const Embedding& embedding, const Mapper& mapper, const S& file);
};/* class Writer */

#define WRITER Writer::getInstance()

}/* namespace TriangulationPlanarEmbedding */
