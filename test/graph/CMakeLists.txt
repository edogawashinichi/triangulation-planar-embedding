aux_source_directory(. TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

include_directories(../../src)

add_executable(test_graph ${TEST_LIST})

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
