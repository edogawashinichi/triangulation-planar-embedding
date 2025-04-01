/* math.h */

#pragma once

#include "notation.h"
#include <functional>
#include <algorithm>
#include <numeric>

namespace TriangulationPlanarEmbedding {

/* u splice v ----> w */
template <typename T>
void splice(const std::vector<T>& u, const std::vector<T>& v, std::vector<T>* w) {
  /* WARNING: unneccessary to locate for w */
  w->insert(w->end(), u.begin(), u.end());
  w->insert(w->end(), v.begin(), v.end());
}/* splice */

/* return i such that vector[i]==t otherwise return -1 */
template<typename T>
int find_index_in_vector(const T& t, const std::vector<T>& vector) {
  auto iter = std::find(vector.begin(), vector.end(), t);
  if (iter == vector.end()) {
    return -1;
  } else {
    return std::distance(vector.begin(), iter);
  }/* if else */
}/* find_index_in_vector */

/* return whether vector contains element t */
template<typename T>
bool find_element_in_vector(const T& t, const std::vector<T>& vector) {
  return std::find(vector.begin(), vector.end(), t) != vector.end();
}/* find_element_in_vector */

/* return lhs==rhs */
template<typename T>
bool equal(const std::vector<std::vector<T>>& lhs, const std::vector<std::vector<T>>& rhs) {
  if (lhs.size() != rhs.size()) return false;
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) return false;
  }/* for */
}/* equal */

/* add element to vector if no duplicate */
template<typename T>
bool no_duplicate_add(const T& element, std::vector<T>* vector) {
  if (find_element_in_vector<T>(element, *vector)) return false;
  vector->emplace_back(element);
  return true;
}/* no_duplicate_add */

/* the number of choosing n items from k items */
LL combination(const size_t n, const size_t k);

/* return n!=1*2*3*...*n */
size_t fact(const size_t n);

/* no same element in container */
template<typename T>
bool distinct(const std::vector<std::vector<T>>& vvt) {
  for (size_t i = 0; i < vvt.size(); ++i) {
    for (size_t j = i + 1; j < vvt.size(); ++j) {
      if (vvt[i] == vvt[j]) return false;
    }/* for j */
  }/* for i */
}/* distinct */

/* whether X-->Y is a function */
template<typename T>
bool function(const std::vector<T>& X, const std::vector<T>& Y, std::unordered_map<T, T>* f) {
  /* assuming: X.size == Y.size */
  bool res = true;
  f->clear();
  for (size_t i = 0; i < X.size(); ++i) {
    const T& x = X[i];
    const T& y = Y[i];
    if (!f->count(x)) {
      (*f)[x] = y;
    } else if ((*f)[x] != y) {
      /* same x --> distinct y */
      res = false;
      break;
    }/* else if */
  }/* for */
  if (!res) f->clear();
  return res;
}/* function */

/* X --f--> Y */
template<typename T>
void map(const std::vector<T>& X, const std::vector<T>& f, std::vector<T>* Y) {
  /* assuming: X in domain of f */
  /* assuming: X and Y have the same domain */
  /* T : size_t / int / long (discrete types only) */
  /* WARNING: function transform requires that Y must be constructed before usage */
  Y->resize(X.size());
  std::transform(X.begin(), X.end(), Y->begin(), [&](const size_t x){return f[x];});
}/* map */

/* C = A - B */
template<typename T>
void diff(const std::vector<T>& A, const std::vector<T>& B, std::vector<T>* C) {
  C->clear();
  for (const auto& a : A) {
    auto iter = std::find(B.begin(), B.end(), a);
    if (iter != B.end()) continue;
    C->emplace_back(a);
  }/* for A */
}/* diff */

template<typename T>
void diff(const std::vector<T>& A, const std::vector<T>& B, std::unordered_set<T>* C) {
  std::vector<T> V;
  diff<T>(A, B, &V);
  *C = std::move(std::unordered_set<T>(V.begin(), V.end()));
}/* diff */

template<typename T>
void diff(const US<T>& A, const US<T>& B, US<T>* C) {
  C->clear();
  for (const T& a : A) {
    if (B.count(a)) continue;
    C->insert(a);
  }
}/* diff */

/* return A cap B */
template<typename T>
bool cap(const std::vector<T>& A, const std::vector<T>& B, std::unordered_set<T>* C) {
  C->clear();
  for (const T& a : A) {
    auto iter = std::find(B.begin(), B.end(), a);
    if (iter == B.end()) continue;
    C->insert(a);
  }/* for a */
  return C->size() > 0;
}/* cap */

/* return A cap B nonempty */
template<typename T>
bool cap(const std::vector<T>& A, const std::vector<T>& B) {
  std::unordered_set<T> C;
  return cap<T>(A, B, &C);
}/* cap */

/* return A cap B */
template<typename T>
bool cap(const std::vector<T>& A, const std::vector<T>& B, std::vector<T>* C) {
  std::unordered_set<T> set;
  bool res = cap<T>(A, B, &set);
  C->clear();
  for (const auto& ele : set) {
    C->emplace_back(ele);
  }
  return res;
}/* cap */

/* return vector {0, 1, ..., n-1} */
/* T: int / size_t / long long */
template<typename T>
std::vector<T> id(const size_t n) {
  std::vector<T> res(n, 0);
  int a = 0;
  std::generate(res.begin(), res.end(), [&]{return a++;});
  return res;
}/* id */

template<typename T>
bool symmetry(const std::vector<std::pair<T, T>>& vtt) {
  /* assuming: type T has implemented hash function */
  std::unordered_map<T, T> map;
  for (const auto& tt : vtt) {
    map[tt.first] = tt.second;
  }/* for */
  for (const auto& kv : map) {
    if (!map.count(kv.second)) return false;
    if (map.at(kv.second) != kv.first) return false;
  }/* for */
  return true;
}/* symmetry */

/* dictionary sort for pairs (x, y) < (a, b) <==> (x<a) || (x==a && y<b) */
template<typename T>
void dict_sort(std::vector<std::pair<T, T>>& vtt, const bool ascend = true) {
  auto cmp = [&](const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) -> bool {
    if (lhs.first != rhs.first) return (lhs.first < rhs.first) == ascend;
    return (lhs.second < rhs.second) == ascend;
  };
  std::sort(vtt.begin(), vtt.end(), cmp);
}/* dict_sort */

/* dictionary sort for vectors (u1, u2, ..., un) < (v1, v2, ..., vn) */
template<typename T>
void dict_sort(std::vector<std::vector<T>>& vv, const bool ascend = true) {
  auto cmp = [&](const std::vector<T>& lhs, const std::vector<T>& rhs) -> bool {
    const size_t n = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    for (size_t i = 0; i < n; ++i) {
      if (lhs[i] == rhs[i]) continue;
      return (lhs[i] < rhs[i]) == ascend;
    }
    return (lhs.size() <= rhs.size()) == ascend;
  };
  std::sort(vv.begin(), vv.end(), cmp);
}/* dict_sort */

/* specially cycle_sort is for kempe chain components around a ring */

/* cycle_sort for vector with cycle */
template<typename T>
void cycle_sort(std::vector<T>& v, const size_t cycle, const bool ascend = true) {
  /* assuming: v is continuous around the cycle */
  if (v.empty()) return;
  if (ascend) {
    std::sort(v.begin(), v.end());
  } else {
    std::sort(v.begin(), v.end(), std::greater<T>());
  }/* if else */
  bool gap = false;
  size_t i = 0;
  for (; i < v.size() - 1; ++i) {
    if (1 == v[i] - v[i+1] || 1 == v[i+1] - v[i]) continue;
    gap = true;
    break;
  }/* for */
  if (gap) {
    std::vector<T> temp;
    for (size_t j = i + 1; j < v.size(); ++j) {
      temp.emplace_back(v[j]);
    }/* for */
    for (size_t j = 0; j <= i; ++j) {
      temp.emplace_back(v[j]);
    }/* for */
    v.swap(temp);
  }/* if */
}/* cycle_sort */

/* cycle_sort for vector vector with cycle */
template<typename T>
void cycle_sort(std::vector<std::vector<T>>& vv, const size_t cycle, const bool ascend = true) {
  /* assuming: each v in vv is continuous around the cycle */
  /* assuming: any distinct u,v in vv don't overlap */
  for (auto& v : vv) {
    cycle_sort<T>(v, cycle, ascend);
  }
  auto cmp = [&](const std::vector<T>& lhs, const std::vector<T>& rhs) -> bool {
    if (lhs.empty() || rhs.empty()) {
      return lhs.empty() == ascend;
    }
    return ascend ? lhs.back() < rhs.back() : lhs.front() > rhs.front();
  };
  std::sort(vv.begin(), vv.end(), cmp);
}/* cycle_sort */

/* max of 3 elements */
/* T: value type */
template<typename T>
T max(const T& a, const T& b, const T& c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}/* max */

/* summation of a vector */
/* T: value type */
template<typename T>
T sum(const std::vector<T>& v) {
  return std::accumulate(v.begin(), v.end(), 0);
}/* sum */

}/* namespace TriangulationPlanarEmbedding */
