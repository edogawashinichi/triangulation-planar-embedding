aux_source_directory(../../src/io TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

include_directories(../../src)

# dynamic library for jsoncpp
set(lib_DIR /usr/lib64/)
find_package(${lib_DIR})

add_executable(test_reader test_reader.cxx ${TEST_LIST})

# dynamic library loaded during running-time
target_link_libraries(test_reader libjsoncpp.so)

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
