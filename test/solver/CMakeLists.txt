# .cxx files
aux_source_directory(. TEST_LIST)
message("TEST_LIST=${TEST_LIST}")

aux_source_directory(../../src/common SRC_LIST1)
message("SRC_LIST1=${SRC_LIST1}")
aux_source_directory(../../src/solver SRC_LIST2)
message("SRC_LIST2=${SRC_LIST2}")
aux_source_directory(../../src/searcher SRC_LIST3)
message("SRC_LIST3=${SRC_LIST3}")
aux_source_directory(../../src/tiler SRC_LIST4)
message("SRC_LIST4=${SRC_LIST4}")
aux_source_directory(../../src/io SRC_LIST5)
message("SRC_LIST4=${SRC_LIST5}")

# .h files
include_directories(../../src)

# main function .cxx file and other .cxx files
add_executable(test_solver ${TEST_LIST} ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4} ${SRC_LIST5})

# dynamic library for jsoncpp
set(lib_DIR /usr/lib64/)
find_package(${lib_DIR})
# dynamic library loaded during running-time
target_link_libraries(test_solver libjsoncpp.so)

set(PROJECT_SOURCE_DIR /mnt/triangulation-planar-embedding)
message("PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")

# obj files
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
