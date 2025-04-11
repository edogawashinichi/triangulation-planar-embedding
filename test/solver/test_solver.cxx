/* test_solver.cxx */

#include "../../src/solver/ring_in_ring.h"
#include "../../src/solver/solver_ring_in_ring.h"
#include "../../src/topology/icosahedron.h"
#include "../../src/topology/icosa_3_6_6.h"
#include "../../src/topology/icosa_3_7_4.h"
#include "../../src/io/reader.h"
#include "../../src/io/writer.h"

using namespace TriangulationPlanarEmbedding;

void test_a_triangulation_file(const S& triangulation) {
  Config config;
  READER.readConfig(G_CONFIG_FILE_PATH, &config);
  Graph graph;
  Mapper mapper;
  const S json(".json");
  const S graph_file(G_GRAPH_DIR + triangulation + json);
  READER.readGraph(graph_file, &mapper, &graph);
  Embedding embedding;
  SOLVER_RING_IN_RING.run(graph, config, &embedding);
  const S embedding_file(G_EMBEDDING_DIR + triangulation + json);
  WRITER.writeEmbedding(embedding, mapper, embedding_file);
}

TEST_START(0)
  RingResult result;
  INFO_OBJ(result)
  result.showStructure(std::cout);
  SHOW_VAR_ENDL(std::cout, result.size())
TEST_END(0)

TEST_START(1)
  const Graph& graph = ICOSAHEDRON;
  Config config(0.5, 0.1);
  Embedding embedding;
  SOLVER_RING_IN_RING.run(graph, config, &embedding);
  INFO_OBJ(embedding)
TEST_END(1)

TEST_START(2)
  const Graph& graph = ICOSA_3_6_6;
  Config config(0.5, 0.1);
  Embedding embedding;
  SOLVER_RING_IN_RING.run(graph, config, &embedding);
  INFO_OBJ(embedding)
TEST_END(2)

TEST_START(3)
  const Graph& graph = ICOSA_3_7_4;
  Config config(0.5, 0.1);
  Embedding embedding;
  SOLVER_RING_IN_RING.run(graph, config, &embedding);
  INFO_OBJ(embedding)
TEST_END(3)

TEST_START(4)
  test_a_triangulation_file("icosahedron");
  test_a_triangulation_file("icosa_3_6_6");
  test_a_triangulation_file("icosa_3_7_4");
TEST_END(4)

MAIN_START
  TEST(0)
  TEST(1)
  TEST(2)
  TEST(3)
  TEST(4)
MAIN_END
