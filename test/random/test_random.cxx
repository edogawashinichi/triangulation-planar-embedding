/* test_random.cxx */

#include "../../src/common/random.h"
#include "../../src/common/debug.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  DEBUG_COUT << G_HISTORY_SEED << ENDL;
  bool res_bet = bet(0.1f);
  SHOW_VAR_ENDL(std::cout, res_bet);
  DEBUG_COUT << G_HISTORY_SEED << ENDL;
  size_t res_choose = randomChoose(10);
  SHOW_VAR_ENDL(std::cout, res_choose);
  DEBUG_COUT << G_HISTORY_SEED << ENDL;
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
