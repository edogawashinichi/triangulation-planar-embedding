/* test_writer.cxx */

#include "../../src/io/writer.h"
#include "../../src/io/reader.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  const S triangulation("triangle");
  const S json(".json");
  Mapper mapper;
  Graph graph;
  const S graph_file(G_GRAPH_DIR + triangulation + json);
  res = res && READER.readGraph(graph_file, &mapper, &graph);
  INFO_OBJ(mapper)
  DEBUG_OBJ(graph)
  const MIPFF embedding_data = {
    {0,{0,1}},
    {1,{-0.866,-0.5}},
    {2,{0.866,-0.5}}
  };
  Embedding embedding(embedding_data);
  VERBOSE_OBJ(embedding)
  const S embedding_file(G_EMBEDDING_DIR + triangulation + json);
  res = res && WRITER.writeEmbedding(embedding, mapper, embedding_file);
TEST_END(0)

MAIN_START
  TEST(0)
MAIN_END
