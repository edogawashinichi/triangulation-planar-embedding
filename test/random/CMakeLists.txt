# .cxx files
aux_source_directory(. TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

aux_source_directory(../../src/common SRC_LIST1)
message("SRC_LIST1=${SRC_LIST1}")

# .h files
include_directories(../../src)

# main function .cxx file and other .cxx files
add_executable(test_random ${TEST_LIST} ${SRC_LIST1})

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

# obj files
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
