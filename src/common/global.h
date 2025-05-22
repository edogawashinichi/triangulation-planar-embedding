/* global.h */

#pragma once

#include <string>
using std::string;

namespace TriangulationPlanarEmbedding {

/* directory */

const string G_ROOT_DIR("/mnt/triangulation-planar-embedding/");
const string G_CONFIG_FILE_PATH(G_ROOT_DIR + "data/config.json");
const string G_GRAPH_DIR(G_ROOT_DIR + "data/input/");
const string G_EMBEDDING_DIR(G_ROOT_DIR + "data/output/");

/* debug */

extern bool G_INFO_MODE;
extern bool G_DEBUG_MODE;
extern bool G_VERBOSE_MODE;

/* math */

const double PI = 3.1415926;
const unsigned int G_N = 1000000; /* to transform from float to int */

/* random */

extern unsigned int G_HISTORY_SEED;

}/* namespace TriangulationPlanarEmbedding */
