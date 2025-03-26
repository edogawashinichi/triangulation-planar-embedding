/* test_reader.cxx */

#include "../../src/io/reader.h"

using namespace TriangulationPlanarEmbedding;

TEST_START(0)
  Config config;
  res = res && READER.readConfig(G_CONFIG_FILE_PATH, &config);
  INFO_OBJ(config)
TEST_END(0)

TEST_START(1)
  Mapper mapper;
  Graph graph;
  const S graph_file(G_GRAPH_DIR + "icosahedron.json");
  res = res && READER.readGraph(graph_file, &mapper, &graph);
  DEBUG_OBJ(mapper)
  VERBOSE_OBJ(graph)
TEST_END(1)

MAIN_START
  TEST(0)
  TEST(1)
MAIN_END
