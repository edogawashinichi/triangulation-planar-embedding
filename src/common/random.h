/* random.h */

#pragma once

#include "notation.h"

namespace TriangulationPlanarEmbedding {

/* Bernoulli experiment */
bool bet(const float probability);

/* randomly choose k distinct elements with equivalent probability from {0, 1, ..., n-1} */
VI randomChoose(const size_t n, const size_t k);

/* randomly choose an element with frequency f={f0, f1, ...} from {0, 1, ..., n-1} where n=f.size() */
size_t randomChoose(const VI& f);

/* randomly choose an element with probability p={p0, p1, ...} from {0, 1, ..., n-1} where n=p.size() */
size_t randomChoose(const VF& p);

/* randomly choose an element with equivalent probability from {0, 1, ..., n-1} */
size_t randomChoose(const size_t n);

}/// namespace TriangulationPlanarEmbedding
