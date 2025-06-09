/* complete_result.h */

#pragma once

#include "complete_graph.h"
#include "ring.h"

namespace TriangulationPlanarEmbedding {

using CompleteOne = CompleteGraph<1>;
using CompleteTwo = CompleteGraph<2>;
using CompleteThree = CompleteGraph<3>;

class CompleteOneResult : public Ring {
public:
  inline CompleteOneResult() : Ring(1) {
  }/* constructor default */
  inline CompleteOneResult(const I n) : Ring(n) {
    /* constructor for derived classes */
  }/* constructor */
  inline I& u() {
    return Ring::vertices_[0];
  }/* u */
  inline I U() const {
    return Ring::vertices_[0];
  }/* U */
  inline void set(const I u) {
    this->u() = u;
  }/* set */
  inline virtual void clear() {
    this->set(0);
  }/* clear */
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    const I u = this->U();
    SHOW_VAR_ENDL(cout, u)
  }/* show */
};/* class CompleteOneResult */

class CompleteTwoResult : public CompleteOneResult {
public:
  inline CompleteTwoResult() : CompleteOneResult(2) {
  }/* constructor default */
  inline CompleteTwoResult(const I n) : CompleteOneResult(n) {
    /* constructor for derived classed */
  }/* constructor */
  inline CompleteTwoResult(const I u, const I v) : CompleteOneResult(2) {
    this->set(u, v);
  }/* constructor */
  inline I& v() {
    return Ring::vertices_[1];
  }/* v */
  inline I V() const {
    return Ring::vertices_[1];
  }/* V */
  inline void set(const I u, const I v) {
    this->u() = u;
    this->v() = v;
  }/* set */
  inline virtual void clear() override {
    this->set(0, 0);
  }/* clear */
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    const I u = CompleteOneResult::U();
    const I v = this->V();
    SHOW_VAR_ENDL(cout, u, v)
  }/* show */
};/* class CompleteTwoResult */

class CompleteThreeResult : public CompleteTwoResult {
public:
  inline CompleteThreeResult() : CompleteTwoResult(3) {
  }/* constructor default */
  inline I& w() {
    return Ring::vertices_[2];
  }/* w */
  inline I W() const {
    return Ring::vertices_[2];
  }/* W */
  inline CompleteThreeResult(const I u, const I v, const I w) : CompleteTwoResult(3) {
    this->set(u, v, w);
  }/* constructor */
  inline void set(const I u, const I v, const I w) {
    this->u() = u;
    this->v() = v;
    this->w() = w;
  }/* set */
  inline virtual void clear() override {
    this->set(0, 0, 0);
  }/* clear */
  inline virtual void show(std::ostream& cout) const override {
    TEST_RETURN
    const I u = this->U();
    const I v = this->V();
    const I w = this->W();
    SHOW_VAR_ENDL(cout, u, v, w)
  }/* show */
};/* class CompleteThreeResult */

}/* namespace TriangulationPlanarEmbedding */
