/* ring_in_ring_trimmer.h */

#pragma once

#include "ring_in_ring.h"
#include "../common/debug.h"

namespace TriangulationPlanarEmbedding {

class RingInRingTrimmer {
SINGLETON_ASSERTION(RingInRingTrimmer)
public:
  /* remove none adjacent duplicate vertex */
  inline void run(const RingInRing& ring, RingInRing* trimmed_ring) {
    trimmed_ring->clear();
    if (ring.size() <= 1) {
      *trimmed_ring = ring;
      return;
    }/* if */
    /* ring size >= 2 */
    VERBOSE_START(RingInRingTrimmer::run)
    const I w = ring.getConst(0).getVertex();
    trimmed_ring->add(w);
    const I n = ring.size();
    for (size_t i = 1; i <= n - 2; ++i) {
      const I u = ring.getConst(i - 1).getVertex();
      const I v = ring.getConst(i).getVertex();
      if (v == u) continue;
      trimmed_ring->add(ring.getConst(i));
    }/* for */
    const I u = ring.getConst(n - 2).getVertex();
    const I v = ring.getConst(n - 1).getVertex();
    if (v != u && v != w) {
      trimmed_ring->add(ring.getConst(n - 1));
    }/* if */
    VERBOSE_END(RingInRingTrimmer::run)
  }/* run */
  inline void run(RingInRing* ring) {
    RingInRing trimmed_ring;
    this->run(*ring, &trimmed_ring);
    std::swap(*ring, trimmed_ring);
  }/* run */
};/* class RingInRingTrimmer */

#define RING_IN_RING_TRIMMER RingInRingTrimmer::getInstance()

}/* namespace TriangulationPlanarEmbedding */
