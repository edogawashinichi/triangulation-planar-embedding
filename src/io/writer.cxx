/* writer.cxx */

#include "writer.h"

#include <fstream>
#include <jsoncpp/json/json.h>

#define WRITE_JSON_START(file) \
std::ofstream outfile(file);   \
if (!outfile.is_open()) {      \
  return false;                \
}                              \
Json::Value root;

#define WRITE_JSON_END         \
Json::StyledWriter sw;          \
outfile << sw.write(root);     \
outfile.close();               \
return true;

namespace TriangulationPlanarEmbedding {

bool Writer::writeEmbedding(const Embedding& embedding, const Mapper& mapper, const S& file) {
  WRITE_JSON_START(file)

  for (const auto& kv : embedding.getConst()) {
    const I vertex = kv.first;
    const S& string = mapper.getString(vertex);
    const Point& point = kv.second;
    Json::Value coordinate;
    coordinate.append(Json::Value(point.x_));
    coordinate.append(Json::Value(point.y_));
    root[string] = coordinate;
  }/* for */

  WRITE_JSON_END
}/* Writer::writeEmbedding */

}/* namespace TriangulationPlanarEmbedding */
