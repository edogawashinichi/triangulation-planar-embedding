#!/usr/bin/sh

echo "start makemake ..."

ROOT_DIR=/mnt/triangulation-planar-embedding
BUILD_DIR=${ROOT_DIR}/build
TEST_DIR=${ROOT_DIR}/bin
SCRIPT_DIR=${ROOT_DIR}/script

function emptyFolder() {
  folder=$1
  if [ -d ${folder} ]; then
    rm -rf ${folder}
    echo "remove existed folder ${folder}"
  fi
  mkdir ${folder}
  echo "create folder ${folder}"
}

# empty last built result
cd ${ROOT_DIR}
emptyFolder ${BUILD_DIR}
emptyFolder ${TEST_DIR}

# make
cd ${BUILD_DIR}
cmake ..
make
cd ..

# test
cd ${SCRIPT_DIR}
bash test.sh
cd ..

echo "end makemake ..."
