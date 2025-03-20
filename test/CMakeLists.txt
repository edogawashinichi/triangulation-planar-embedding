aux_source_directory(. TEST_LIST)

include_directories(../src)

add_executable(test_graph ${TEST_LIST})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
