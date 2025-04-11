/* balance_tiler.h */

#pragma once

#include "tiler.h"
#include "../geometry/polygon.h"

namespace TriangulationPlanarEmbedding {

class BalanceTiler : public Tiler {
SINGLETON_ASSERTION(BalanceTiler)
public:
  virtual void run(const Graph& graph, const Config& config, const MergedRingResult& rings, Embedding* embedding) override;
protected:
  void addEmbedding(const MergedRingInRing& ring, const RegularPolygon& polygon, Embedding* embedding);
  F findBalancedRotation(const MergedRingInRing& inner_ring, const MergedRingInRing& ring, const Embedding& embedding, const RegularPolygon& polygon);
  PFF getRotationQuantity(const MergedRingInRing& inner_ring, const MergedRingInRing& ring, const Embedding& embedding, const RegularPolygon& polygon);
};/* class BalanceTiler */

#define BALANCE_TILER BalanceTiler::getInstance()

}/* namespace TriangulationPlanarEmbedding */
