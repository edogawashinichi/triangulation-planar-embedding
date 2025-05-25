/* random.cxx */

#include "random.h"
#include "global.h"
#include "math.h"
#include "debug.h"
#include <random>
#include <chrono>

#define GET_TIMESTAMP(timestamp) \
auto now = std::chrono::system_clock::now(); \
auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()); \
auto timestamp = static_cast<unsigned int>(ms.count());

#define UPDATE_HISTORY_SEED(adder) \
G_HISTORY_SEED += adder;

#define RANDOM_ENVIRONMENT(random_engine) \
std::random_device device; \
unsigned int device_adder = device(); \
UPDATE_HISTORY_SEED(device_adder) \
GET_TIMESTAMP(timestamp) \
UPDATE_HISTORY_SEED(timestamp) \
std::mt19937 random_engine(G_HISTORY_SEED); 

#define UNIFORM_DISTRIBUTION(sum, res) \
RANDOM_ENVIRONMENT(engine) \
std::uniform_int_distribution<int> distribution(0, sum - 1); \
const unsigned int res = distribution(engine);

namespace TriangulationPlanarEmbedding {

bool bet(const float probability) {
  UNIFORM_DISTRIBUTION(G_N, res)
  return res < G_N * probability;
}/* bet */

VI randomChoose(const size_t n, const size_t k) {
  RANDOM_ENVIRONMENT(random_engine)
  VI all = id<size_t>(n);
  std::shuffle(all.begin(), all.end(), random_engine);
  return VI(all.begin(), all.begin() + k);
}/* randomChoose */

void shuffle(VI* vector) {
  RANDOM_ENVIRONMENT(random_engine)
  std::shuffle(vector->begin(), vector->end(), random_engine);
}/* shuffle */

VI randomOrder(const size_t n) {
  return randomChoose(n, n);
}/* randomOrder */

size_t randomChoose(const VF& probability) {
  VERBOSE_VI(probability)
  const auto& p = probability;
  VI f(p.size(), 0);
  std::transform(p.begin(), p.end(), f.begin(), [&](const float& ele){ return static_cast<size_t>(ele * G_N); });
  return randomChoose(f);
}/* randomChoose */

size_t randomChoose(const VI& frequency) {
  VERBOSE_VI(frequency)
  const auto& f = frequency;
  const size_t n = f.size();
  const unsigned int sum = std::accumulate(f.begin(), f.end(), 0);
  /* if (sum == 0) return -1; */
  UNIFORM_DISTRIBUTION(sum, res)
  size_t i = 0;
  unsigned int pref_sum = 0;
  for (; i < n; ++i) {
    pref_sum += f[i];
    if (res < pref_sum) break;
  }/* for */
  return i;
}/* randomChoose */

size_t randomChoose(const size_t n) {
  return randomChoose(n, 1).front();
}/* randomChoose */

}/// namespace TriangulationPlanarEmbedding
