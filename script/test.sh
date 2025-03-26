#!/usr/bin/sh

echo "start test ..."

ROOT_DIR=/mnt/triangulation-planar-embedding
TEST_DIR=${ROOT_DIR}/bin

# bin exists
if [ -d ${TEST_DIR} ]; then
  echo "bin dir ${TEST_DIR} exists!"
else
  echo "bin dir ${TEST_DIR} not exists!"
fi

# test
cd ${TEST_DIR}
bin_files=$(ls)
for file in ${bin_files}; do
  echo "${file}"
  ./${file}
done
cd ..

echo "end test ..."
