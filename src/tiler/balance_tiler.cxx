/* balance_tiler.cxx */

#include "balance_tiler.h"

namespace TriangulationPlanarEmbedding {

void BalanceTiler::addEmbedding(const MergedRingInRing& ring, const RegularPolygon& polygon, Embedding* embedding) {
  /* assuming ring size == polygon size */
  /* ring node vertex i <--> polygon point i */
  for (size_t i = 0; i < ring.size(); ++i) {
    const I vertex = ring.getConst(i).getVertex();
    embedding->add(vertex, polygon.getConst(i));
  }/* for */
}/* BalanceTiler::addEmbedding */

void BalanceTiler::run(const Graph& graph, const Config& config, const MergedRingResult& rings, Embedding* embedding) {
  DEBUG_START(BalanceTiler::run)
  embedding->clear();

  /* assuming rings size >= 3 */
  const auto& l = config.getMinDist();
  const auto& s = config.getMinArea();
  SHOW_VAR_ENDL(std::cout, l, s)

  /* innermost ring */
  const int k = rings.size();
  int i = k - 1;
  const auto& ring = rings.getConst(i);
  RegularPolygon polygon(ring.size());
  DEBUG_OBJ(polygon)
  const F area = polygon.areaSSC();
  const F area_ratio = sqrt(s / area);
  const F innermost_radius = std::max(l, area_ratio);
  SHOW_VAR_ENDL(std::cout, area, area_ratio, innermost_radius)
  polygon.zoom(innermost_radius);
  DEBUG_OBJ(polygon)
  this->addEmbedding(ring, polygon, embedding);

  /* the rest rings */
  for (; i >= 1; --i) {
    const auto& inner_ring = rings.getConst(i);
    const auto& ring = rings.getConst(i - 1);
    const F radius = pow(3, k - i) * innermost_radius;
    const I n = ring.size();
    RegularPolygon polygon(n, radius);
    const F alpha = this->findBalancedRotation(inner_ring, ring, *embedding, polygon);
    SHOW_VAR_ENDL(std::cout, i, alpha)
    polygon.rotate(alpha);
    this->addEmbedding(ring, polygon, embedding);
  }/* for i */
  
  DEBUG_END(BalanceTiler::run)
}/* BalanceTiler::run */

F BalanceTiler::findBalancedRotation(const MergedRingInRing& inner_ring, const MergedRingInRing& ring, const Embedding& embedding, const RegularPolygon& polygon) {
  /* TODO: optimize by nonuniform-refinement and monotonicity */
  DEBUG_START(BalanceTiler::findBalanceRotation)
  F alpha = 0.0f;
  F best_sum = 1e10f;
  F best_diff = 1e10f;
  const F THETA_START = -2 *PI;
  const F THETA_END = 2 * PI;
  const F DELTA = 0.02f;/* 0.02 radians == 1.146 degrees */
  const F DELTA_SUM = 0.01f;
  const F DELTA_DIFF = 0.01f;
  for (F theta = THETA_START; theta <= THETA_END; theta += DELTA) {
    RegularPolygon rotated_polygon(polygon);
    rotated_polygon.rotate(theta);
    const auto& quantity = this->getRotationQuantity(inner_ring, ring, embedding, rotated_polygon);
    const auto& sum = quantity.first;
    const auto& diff = quantity.second;
    if (sum < best_sum + DELTA_SUM && diff < best_diff + DELTA_DIFF) {
      best_sum = sum;
      best_diff = diff;
      alpha = theta;
    }/* if */
    SHOW_VAR_ENDL(std::cout, theta, sum, diff)
    SHOW_VAR_ENDL(std::cout, alpha, best_sum, best_diff)
  }/* for theta */
  DEBUG_END(BalanceTiler::findBalanceRotation)
  return alpha;
}/* BalanceTiler::findBalanceRotation */

PFF BalanceTiler::getRotationQuantity(const MergedRingInRing& inner_ring, const MergedRingInRing& ring, const Embedding& embedding, const RegularPolygon& polygon) {
  DEBUG_START(BalanceTiler::getRotationQuantity)
  F res_diff = 0.0f;
  F res_sum = 0.0f;
  for (size_t i = 0; i < inner_ring.size(); ++i) {
    const auto& node = inner_ring.getConst(i);
    const auto& vertex = node.getVertex();
    const auto& point = embedding.constPoint(vertex);
    const auto& multi_parents = node.getMultiParents();
    INFO_OBJ(node)
    INFO_OBJ(point)

    /* vertex parent parent */
    for (const auto& parents : multi_parents) {
      const auto& p = parents.first;
      const auto& q = parents.second;
      const auto& point_p = polygon.getConst(p);
      const auto& point_q = polygon.getConst(q);
      INFO_OBJ(point_p)
      INFO_OBJ(point_q)
      const auto& ls_p = (point - point_p).lengthSquare();
      const auto& ls_q = (point - point_q).lengthSquare();
      SHOW_VAR_ENDL(std::cout, ls_p, ls_q)
      res_diff += fabs(ls_p - ls_q);/* WARNING: abs will round off */
      res_sum += 2.0f * std::max(ls_p, ls_q);
    }/* for parents */

    /* vertex vertex common_parent */
    const size_t next_i = (i + 1) % inner_ring.size();
    const auto& next_node = inner_ring.getConst(next_i);
    const auto& next_point = embedding.constPoint(next_node.getVertex());
    VI common_parent;
    cap<I>(node.getParentsVector(), next_node.getParentsVector(), &common_parent);/* |common_parent|==1 */
    const auto& parent_point = polygon.getConst(common_parent.front());
    const auto& ls_point = (point - parent_point).lengthSquare();
    const auto& ls_next = (next_point - parent_point).lengthSquare();
    SHOW_VAR_ENDL(std::cout, ls_point, ls_next)
    res_diff += 100.0f * fabs(ls_point - ls_next);
    res_sum += 200.0f * std::max(ls_point, ls_next);

    SHOW_VAR_ENDL(std::cout, res_diff, res_sum)
  }/* for i */
  DEBUG_END(BalanceTiler::getRotationQuantity)
  return {res_sum, res_diff};
}/* BalanceTiler::getRotationQuantity */

}/* namespace TriangulationPlanarEmbedding */
