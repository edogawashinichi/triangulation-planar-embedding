/* math.cxx */

#include "math.h"

namespace TriangulationPlanarEmbedding {

/* combination number of choosing kk items from n items */
LL combination(const size_t n, const size_t kk) {
  /* assuming: n >= kk */
  const size_t k = (kk > n - kk) ? n - kk : kk;
  LL res = 1;
  const LL base = static_cast<LL>(n) - k + 1;
  for (LL i = base; i <= static_cast<LL>(n); ++i) {
    res *= i;
    res /= (i - base + 1);
  }/* for */
  return res;
}/* combination */

/* factorial of n : n! */
size_t fact(const size_t n) {
  /* assuming: n! is no more than max value of size_t */
  size_t res = 1;
  for (size_t i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}/* fact */

}/* namespace TriangulationPlanarEmbedding */
