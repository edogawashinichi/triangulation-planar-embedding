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

#define SS(some) STR(some)

#define SPACE(k) S(k, ' ')

#define HINT S(": ")

#define TO S("->")

#define ENDL "\n"

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

/* show variables 
   max supporting number is 5
*/

#define SHOW_VAR_1(cout, var) \
cout << SS(var) << "=" << var;
#define SHOW_VAR_2(cout, var, ...) \
SHOW_VAR_1(cout, var)              \
cout << SPACE(1);                  \
SHOW_VAR_1(cout, __VA_ARGS__)
#define SHOW_VAR_3(cout, var, ...) \
SHOW_VAR_1(cout, var)              \
cout << SPACE(1);                  \
SHOW_VAR_2(cout, __VA_ARGS__)
#define SHOW_VAR_4(cout, var, ...) \
SHOW_VAR_1(cout, var)              \
cout << SPACE(1);                  \
SHOW_VAR_3(cout, __VA_ARGS__)
#define SHOW_VAR_5(cout, var, ...) \
SHOW_VAR_1(cout, var)              \
cout << SPACE(1);                  \
SHOW_VAR_4(cout, __VA_ARGS__)

#define SHOW_VAR(cout, ...)                                           \
do {                                                                  \
  CONCAT(SHOW_VAR_, PARAMETER_NUMBER(__VA_ARGS__))(cout, __VA_ARGS__) \
} while (0);

#define SHOW_VAR_ENDL(cout, ...) \
SHOW_VAR(cout, __VA_ARGS__)      \
cout << ENDL;

/* show complicated structure */

#define SHOW_VI(cout, vi)  \
for (const I ele : vi) {   \
  cout << ele << SPACE(1); \
}

#define SHOW_VI_ENDL(cout, vi) \
SHOW_VI(cout, vi)              \
cout << ENDL;

#define SHOW_PAIR_WITH_PARENTH(cout, p) \
cout << "(" << p.first << "," << p.second << ")";

#define SHOW_PAIR_WITH_PARENTH_ENDL(cout, p) \
SHOW_PAIR_WITH_PARENTH(cout, p)              \
cout << ENDL;

#define SHOW_MIVI_ENDL(cout, mivi)  \
cout << SS(mivi) << HINT << ENDL;   \
for (const auto& kv : mivi) {       \
  cout << kv.first << HINT;         \
  for (const auto& i : kv.second) { \
    cout << i << SPACE(1);          \
  }                                 \
  cout << ENDL;                     \
}

#define SHOW_MSI_OR_MIS_ENDL(cout, msome)          \
cout << SS(msome) << HINT << ENDL;                 \
for (const auto& kv : msome) {                     \
  cout << kv.first << TO << kv.second << SPACE(1); \
}                                                  \
cout << ENDL;

#define SHOW_VII_ENDL(cout, vii)     \
cout << SS(vii) << HINT;             \
for (const auto& pair : vii) {       \
  SHOW_PAIR_WITH_PARENTH(cout, pair) \
  cout << SPACE(1);                  \
}                                    \
cout << ENDL;

#define SHOW_MIPFF_ENDL(cout, mipff)      \
cout << SS(mipff) << HINT << ENDL;        \
for (const auto& kv : mipff) {            \
  cout << kv.first << TO;                 \
  SHOW_PAIR_WITH_PARENTH_ENDL(cout, kv.second) \
}

#define HINT_INDEX(cout, i) \
cout << i << "th" << HINT;
#define HINT_INDEX_ENDL(cout, i) \
HINT_INDEX(cout, i)              \
cout << ENDL;

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

}/* namespace TriangulationPlanarEmbedding */
