/* reader.cxx */

#include "reader.h"
#include "../common/terminal.h"

#include <fstream>
#include <jsoncpp/json/json.h>

#define READ_JSON_START(file)                 \
DEBUG_START(READ_JSON file)                   \
std::ifstream infile(file, std::ios::binary); \
if (!infile.is_open()) {                      \
  DEBUG_END(READ_JSON file)                   \
  return false;                               \
}                                             \
Json::Reader reader;                          \
Json::Value  root;                            \
if (!reader.parse(infile, root)) {            \
  DEBUG_END(READ_JSON file)                   \
  return false;                               \
}

#define READ_JSON_END               \
infile.close();                     \
DEBUG_END(READ_JSON)                \
return true;

namespace TriangulationPlanarEmbedding {

bool Reader::readConfig(const S& file, Config* config) {
  READ_JSON_START(file)

  config->clear();
  config->min_dist_ = root["min_dist"].asFloat();
  config->min_area_ = root["min_area"].asFloat();

  READ_JSON_END
}/* Reader::readConfig */

bool Reader::readGraph(const S& file, Mapper* mapper, Graph* graph) {
  READ_JSON_START(file)
  
  mapper->clear();
  graph->clear();

  /* create mapper */
  I code = 0;
  Json::Value::Members mem = root.getMemberNames();
  for (auto iter = mem.begin(); iter != mem.end(); ++iter, ++code) {
    //SHOW_ENDL(std::cout, typeid(*iter).name())
    if (typeid(*iter) != typeid(S)) return false;
    if (root[*iter].type() != Json::arrayValue) return false;
    const std::string& str = *iter;
    if (str.length() == 1) {
      const char& ch = str[0];
      if (isdigit(ch)) {
        mapper->add(str, static_cast<size_t>(ch - '0'));
      } else if (islower(ch)) {
        mapper->add(str, static_cast<size_t>(ch - 'a' + 10));
      } else {
        mapper->add(str, static_cast<size_t>(ch - 'A' + 36));
      }/* else */
    } else {
      mapper->add(str, code);
    }/* else */
    const I size = root[*iter].size();
    for (I i = 0; i < size; ++i) {
      const int j = static_cast<int>(i);
      //SHOW_ENDL(std::cout, typeid(root[*iter][j]).name())
      if (root[*iter][j].type() != Json::stringValue) return false;
    }/* for i */
  }/* for iter */

  /* create graph */
  size_t n = 0;
  for (auto iter = mem.begin(); iter != mem.end(); ++iter, ++n) {
    const I u = mapper->getCode(*iter);
    const I size = root[*iter].size();
    for (I i = 0; i < size; ++i) {
      const int j = static_cast<int>(i);
      const I v = mapper->getCode(root[*iter][j].asString());
      graph->add(u, v);
    }/* for i */
  }/* for iter */
  graph->setN(n);
  graph->checkSymmetry();

  READ_JSON_END
}/* Reader::readGraph */

}/* namespace TriangulationPlanarEmbedding */
