/* notation.h */

#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

namespace TriangulationPlanarEmbedding {

/* fundamental type abbreviation */

#define I size_t
#define VI std::vector<I>
#define VVI std::vector<VI>
#define US std::unordered_set
#define SI US<I>
#define UM std::unordered_map
#define MIVI UM<I,VI>
#define S std::string
#define MIS UM<I,S>
#define MSI UM<S,I>
#define F float
#define D double
#define LL long long
#define P std::pair
#define PFF P<F,F>
#define MIPFF UM<I,PFF>

/* fundamental operation */

#define MAP_ADD(map, x, y) \
if (map.count(x)) {        \
  map[x].emplace_back(y);     \
} else {                   \
  map[x] = {y};            \
}

/* singleton pattern */

#define SINGLETON_ASSERTION_WITHOUT_PRIVATE(Class) \
public:                                            \
  inline ~Class() = default;                       \
  inline Class(const Class&) = delete;             \
  inline Class& operator=(const Class&) = delete;  \
  inline static Class& getInstance() {             \
    static Class instance;                         \
    return instance;                               \
  }

#define SINGLETON_ASSERTION(Class)         \
SINGLETON_ASSERTION_WITHOUT_PRIVATE(Class) \
private:                                   \
  inline Class() = default;

/* constructors and assignments of a class with members
   max supporting number of members is 5 */

/* count number of variable arguments of macro, max supporting number 10 */
#define PARAMETER_NUMBER(...) \
PARAMETER_NUMBER_PRIVATE(0, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define PARAMETER_NUMBER_PRIVATE(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

/* concate */
#define CONCAT(x, y) CONCAT_IMPL(x, y)
#define CONCAT_IMPL(x, y) x##y

/* assign */
#define ASSIGN1(rhs, member_) \
member_ = rhs.member_;
#define ASSIGN2(rhs, member0_, member1_) \
ASSIGN1(rhs, member0_)                   \
ASSIGN1(rhs, member1_)
#define ASSIGN3(rhs, member0_, member1_, member2_) \
ASSIGN1(rhs, member0_)                             \
ASSIGN2(rhs, member1_, member2_)
#define ASSIGN4(rhs, member0_, member1_, member2_, member3_) \
ASSIGN1(rhs, member0_)                                       \
ASSIGN3(rhs, member1_, member2_, member3_)
#define ASSIGN5(rhs, member0_, member1_, member2_, member3_, member4_) \
ASSIGN1(rhs, member0_)                                                 \
ASSIGN4(rhs, member1_, member2_, member3_, member4_)
/* at least one member_ parameter for ASSIGN(rhs, ...) */
#define ASSIGN(rhs, ...)                                          \
do {                                                              \
  CONCAT(ASSIGN, PARAMETER_NUMBER(__VA_ARGS__))(rhs, __VA_ARGS__) \
} while (0);

/* swap */
#define SWAP1(rhs, member_) \
std::swap(member_, rhs.member_);
#define SWAP2(rhs, member0_, member1_) \
SWAP1(rhs, member0_)                   \
SWAP1(rhs, member1_)
#define SWAP3(rhs, member0_, member1_, member2_) \
SWAP1(rhs, member0_)                             \
SWAP2(rhs, member1_, member2_)
#define SWAP4(rhs, member0_, member1_, member2_, member3_) \
SWAP1(rhs, member0_)                                       \
SWAP3(rhs, member1_, member2_, member3_)
#define SWAP5(rhs, member0_, member1_, member2_, member3_, member4_) \
SWAP1(rhs, member0_)                                                 \
SWAP4(rhs, member1_, member2_, member3_, member4_)
/* at least one member_ parameter for SWAP(rhs, ...) */
#define SWAP(rhs, ...)                                          \
do {                                                            \
  CONCAT(SWAP, PARAMETER_NUMBER(__VA_ARGS__))(rhs, __VA_ARGS__) \
} while (0);

#define CLASS_CONSTRUCTOR_DEFAULT(Class, ...) \
inline Class() {                              \
} /* constructor default */
#define CLASS_CONSTRUCTOR_DEEPCOPY(Class, rhs, ...) \
inline Class(const Class& rhs) {                    \
  if (this != &rhs) {                               \
    ASSIGN(rhs, __VA_ARGS__)                        \
  }                                                 \
} /* constructor deepcopy */
#define CLASS_CONSTRUCTOR_MOVECOPY(Class, rhs, ...) \
inline Class(Class&& rhs) {                         \
  if (this != &rhs) {                               \
    SWAP(rhs, __VA_ARGS__)                          \
  }                                                 \
} /* constructor movecopy */
#define CLASS_ASSIGNMENT_DEEPCOPY(Class, rhs, ...) \
inline Class& operator=(const Class& rhs) {        \
  if (this != &rhs) {                              \
    ASSIGN(rhs, __VA_ARGS__)                       \
  }                                                \
  return *this;                                    \
} /* assignment deepcopy */
#define CLASS_ASSIGNMENT_MOVECOPY(Class, rhs, ...) \
inline Class& operator=(Class&& rhs) {             \
  if (this != &rhs) {                              \
    SWAP(rhs, __VA_ARGS__)                         \
  }                                                \
  return *this;                                    \
} /* assignment movecopy */

#define CLASS_4_FUNCTIONS(Class, ...)               \
CLASS_CONSTRUCTOR_DEEPCOPY(Class, rhs, __VA_ARGS__) \
CLASS_CONSTRUCTOR_MOVECOPY(Class, rhs, __VA_ARGS__) \
CLASS_ASSIGNMENT_DEEPCOPY(Class, rhs, __VA_ARGS__)  \
CLASS_ASSIGNMENT_MOVECOPY(Class, rhs, __VA_ARGS__)

#define CLASS_5_FUNCTIONS(Class, ...)               \
public:                                             \
CLASS_CONSTRUCTOR_DEFAULT(Class, rhs, __VA_ARGS__)  \
CLASS_4_FUNCTIONS(Class, __VA_ARGS__)

}/* namespace TriangulationPlanarEmbedding */
