/* mapper.h */

#pragma once

#include "common/notation.h"
#include "common/terminal.h"

namespace TriangulationPlanarEmbedding {

class Mapper {
CLASS_5_FUNCTIONS(Mapper, string2code_, code2string_)
public:
  inline void show(std::ostream& cout) const {
    SHOW_MSI_OR_MIS_ENDL(cout, string2code_)
    SHOW_MSI_OR_MIS_ENDL(cout, code2string_)
  }/* show */
  inline void clear() {
    string2code_.clear();
    code2string_.clear();
  }/* clear */
  inline I getCode(const S& string) const {
    return string2code_.count(string) ? string2code_.at(string) : 0;
  }/* getCode */
  inline void add(const S& string, const I code) {
    string2code_[string] = code;
    code2string_[code] = string;
  }/* add */
protected:
  MSI string2code_;
  MIS code2string_;
};/* class Mapper */

}/* namespace TriangulationPlanarEmbedding */
