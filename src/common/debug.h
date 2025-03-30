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
  cout << SS(str) << SPACE(1) << "mode argument" << HINT << CYAN << SS(ch) << RESET << ENDL; \
}

#define HINT_MODE_USAGE(cout, ch, str)                                  \
cout << SS(str) << SPACE(1) << "mode usage" << HINT << ENDL;            \
cout << RED << "./test_xxxx.sh" << SPACE(1) << SS(ch) << RESET << ENDL;

#define CHECK_MODE(cout, ch, str, VAR)   \
if (argc == 2) {                         \
  if (S(argv[1]) == SS(ch)) {            \
    G_##VAR##_MODE = true;               \
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
    std::cout << S_GREEN("return from main!");   \
  }                                              \
  return 0;                                      \
}

/* info debug verbose * obj */

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

/* info debug verbose * start end */

#define MODE_PROC(cout, MODE, proc, msg) \
if (_##MODE) {                           \
  cout << SS(proc) << SPACE(1);          \
  SHOW_ENDL(cout, SS(msg))               \
}

#define INFO_START(msg) \
MODE_PROC(std::cout, INFO, start, msg)
#define INFO_END(msg) \
MODE_PROC(std::cout, INFO, end, msg)

#define DEBUG_START(msg) \
MODE_PROC(std::cout, DEBUG, start, msg)
#define DEBUG_END(msg) \
MODE_PROC(std::cout, DEBUG, end, msg)

#define VERBOSE_START(msg) \
MODE_PROC(std::cout, VERBOSE, start, msg)
#define VERBOSE_END(msg) \
MODE_PROC(std::cout, VERBOSE, end, msg)

}/* namespace TriangulationPlanarEmbedding */
