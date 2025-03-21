#!/usr/bin/sh

echo "start makemake ..."

ROOT_DIR=/mnt/triangulation-planar-embedding
BUILD_DIR=${ROOT_DIR}/build

# create a new build dir
cd ${ROOT_DIR}
if [ -d ${BUILD_DIR} ]; then
  echo "remove build dir: ${BUILD_DIR}!"
  rm -rf ${BUILD_DIR}
else
  echo "no build dir: ${BUILD_DIR}!"
fi
echo "create build dir: ${BUILD_DIR}!"
mkdir ${BUILD_DIR}

# make
cd ${BUILD_DIR}
cmake ..
make
cd ..

echo "end makemake ..."
