/* terminal.h */

/* show in terminal */

#pragma once

#include "notation.h"

#include <iostream>

namespace TriangulationPlanarEmbedding {

/* color control */

#define RESET "\033[0m"   /* Reset */
#define BLACK "\033[30m"  /* Black */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */
#define PURPLE "\033[35m" /* Purple */
#define CYAN "\033[36m"   /* Cyan */
#define WHITE "\033[37m"  /* White */

#define S_BLACK(s) S(BLACK) + S(s) + S(RESET)
#define S_RED(s)   S(RED) + S(s) + S(RESET)
#define S_GREEN(s) S(GREEN) + S(s) + S(RESET)
#define S_YELLOW(s) S(YELLOW) + S(s) + S(RESET)
#define S_BLUE(s) S(BLUE) + S(s) + S(RESET)
#define S_PURPLE(s) S(PURPLE) + S(s) + S(RESET)
#define S_CYAN(s) S(CYAN) + S(s) + S(RESET)
#define S_WHITE(s) S(WHITE) + S(s) + S(RESET)

/* space, endl, separation */

#define STR(some) #some

#define SS(some) S(STR(some))

#define SPACE(k) S(k, ' ')

#define ENDL S("\n")

#define SEPAR(k) S(k, '-')

/* test */

#define S_TEST_SEPAR(separ_half_len, test_index) \
S_YELLOW(SEPAR(separ_half_len)) + S_BLUE(SS(test_##test_index)) + S_YELLOW(SEPAR(separ_half_len))

#define SHOW_SEPAR_ENDL_WITH_TEST(cout, separ_half_len, test_index) \
cout << S_TEST_SEPAR(separ_half_len, test_index) << ENDL;                   \

#define S_TEST_PASS(i) \
S_BLUE(SS(test_##i)) + " " + S_GREEN("PASSED!")

#define S_TEST_FAIL(i) \
S_BLUE(SS(test_##i)) + " " + S_RED("FAILED!")

#define SHOW_ENDL(cout, s) \
cout << s << ENDL;

#define SHOW_SPACE(cout, s, k) \
cout << s << SPACE(k);

#define SHOW_TEST_RES(cout, i)    \
if (res) {                        \
  SHOW_ENDL(cout, S_TEST_PASS(i)) \
} else {                          \
  SHOW_ENDL(cout, S_TEST_FAIL(i)) \
}

#define TEST(i) test_##i();

#define TEST_START(i)                         \
void test_##i() {                             \
  SHOW_SEPAR_ENDL_WITH_TEST(std::cout, 30, i) \
  bool res = true;

#define TEST_END(i)                           \
  SHOW_TEST_RES(std::cout, i)                 \
  SHOW_SEPAR_ENDL_WITH_TEST(std::cout, 30, i) \
}

#define MAIN_START \
int main(int argc, char* argv[]) {

#define MAIN_END                               \
  std::cout << S_GREEN("return from main!\n"); \
  return 0;                                    \
}

}/* namespace TriangulationPlanarEmbedding */
