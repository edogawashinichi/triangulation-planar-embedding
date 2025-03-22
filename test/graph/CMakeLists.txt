aux_source_directory(. TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

#aux_source_directory(../../src/common MORE_LIST)
#message("MORE_LIST=${MORE_LIST}")

include_directories(../../src)

#add_executable(test_graph ${TEST_LIST} ${MORE_LIST})
add_executable(test_graph ${TEST_LIST})

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
