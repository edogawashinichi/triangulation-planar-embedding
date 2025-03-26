/* debug.h */

#pragma once

#include "terminal.h"
#include "global.h"

namespace TriangulationPlanarEmbedding {

#define TEST_RETURN                                     \
if (!G_INFO_MODE && !G_DEBUG_MODE && !G_VERBOSE_MODE) { \
  return;                                               \
}

#define HINT_MODE_ARGUMENT(cout, ch, str, VAR)                              \
if (G_##VAR##_MODE) {                                                       \
  cout << "mode" << HINT << GREEN << SS(str) << RESET << ENDL;              \
} else {                                                                    \
  cout << SS(str) << SPACE(1) << "mode argument" << HINT << SS(ch) << ENDL; \
}

#define HINT_MODE_USAGE(cout, ch, str)                                  \
cout << SS(str) << SPACE(1) << "mode usage" << HINT << ENDL;            \
cout << RED << "./test_xxxx.sh" << SPACE(1) << SS(ch) << RESET << ENDL;

#define CHECK_MODE(cout, ch, str, VAR)   \
if (argc > 1) {                          \
  if (S(argv[1]) == SS(ch)) {            \
    G_##VAR##_MODE = true;               \
  } else {                               \
    HINT_MODE_USAGE(cout, ch, str)       \
  }                                      \
  HINT_MODE_ARGUMENT(cout, ch, str, VAR) \
} else if (argc > 2) {                   \
  HINT_MODE_USAGE(cout, ch, str)         \
}

#define CHECK_INFO_MODE(cout)   \
CHECK_MODE(cout, i, info, INFO)

#define CHECK_DEBUG_MODE(cout)    \
CHECK_MODE(cout, d, debug, DEBUG)

#define CHECK_VERBOSE_MODE(cout)      \
CHECK_MODE(cout, v, verbose, VERBOSE)

#define MAIN_START \
int main(int argc, char* argv[]) { \
  CHECK_INFO_MODE(std::cout)       \
  CHECK_DEBUG_MODE(std::cout)      \
  CHECK_VERBOSE_MODE(std::cout)

#define MAIN_END                                 \
  if (argc > 1) {                                \
    std::cout << S_GREEN("return from main!\n"); \
  }                                              \
  return 0;                                      \
}

#define _VERBOSE \
G_VERBOSE_MODE

#define _DEBUG \
_VERBOSE || G_DEBUG_MODE

#define _INFO \
_DEBUG || G_INFO_MODE

#define SHOW_OBJ(MODE, obj) \
if (_##MODE) { \
  std::cout << SS(obj) << HINT << ENDL; \
  (obj).show(std::cout);                \
}

#define INFO_OBJ(obj) \
SHOW_OBJ(INFO, obj)

#define DEBUG_OBJ(obj) \
SHOW_OBJ(DEBUG, obj)

#define VERBOSE_OBJ(obj) \
SHOW_OBJ(VERBOSE, obj)

}/* namespace TriangulationPlanarEmbedding */
