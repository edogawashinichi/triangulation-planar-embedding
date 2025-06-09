# .cxx files
aux_source_directory(. TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

aux_source_directory(../../src/common SRC_LIST1)
message("SRC_LIST=${SRC_LIST1}")
aux_source_directory(../../src/searcher SRC_LIST2)
message("SRC_LIST=${SRC_LIST2}")

# .h files
include_directories(../../src)

# main function .cxx file and other .cxx files
add_executable(test_walk_searcher ${TEST_LIST} ${SRC_LIST1} ${SRC_LIST2})

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

# obj files
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
