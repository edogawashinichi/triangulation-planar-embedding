#!/usr/bin/sh

# usage: bash test.sh v/d/i test_solver/xxx
#        bash test.sh v/d/i
#        bash test.sh
#
# new usage: bash test.sh v/d/i n 0/1/2/3

echo "start test ..."

ROOT_DIR=/mnt/triangulation-planar-embedding
TEST_DIR=${ROOT_DIR}/test
BIN_DIR=${ROOT_DIR}/bin

# color control
prefix="\033["
reset="\033[0m"
front_red="31"
front_blue="34"
front_green="32"
front_cyan="36"
back_yellow="43"
back_magenta="45"
front_blue_back_yellow="${prefix}${front_blue};${back_yellow}m"
front_green_back_yellow="${prefix}${front_green};${back_yellow}m"
front_cyan_back_magenta="${prefix}${front_cyan};${back_magenta}m"
front_red_back_yellow="${prefix}${front_red};${back_yellow}m"

# count
cd ${TEST_DIR}
test_num=`ls -l|grep "^d"|wc -l`
echo "test number: ${test_num}"
cd ${BIN_DIR}
obj_num=`ls -l|grep "^-"|wc -l`
echo "obj number: ${obj_num}"
if [ ${test_num} -eq ${obj_num} ]; then
  # test
  test_fail_num=0
  cd ${BIN_DIR}
  bin_files=$(ls)
  file_index=-1
  for file in ${bin_files}; do
    let file_index++
    echo -e -n "${prefix}${front_green}m${file_index}${reset} ${front_cyan_back_magenta}${file}${reset}\n"
    if [ $# -gt 2 ]; then
      if [ $2 == n ] && [ $3 -eq ${file_index} ]; then
        echo -e "test file index ${prefix}${front_green}m${file_index}${reset}"
      else
        echo -e "${prefix}${front_red}m  SKIP${reset} ${file} != ${file_index}"
        continue
      fi
    elif [ $# -gt 1 ]; then
      if [ ${file} != test_$2 ]; then
        echo -e "${prefix}${front_red}m  SKIP${reset} ${file} != test_$2"
        continue
      fi
    fi
    if [ $# -gt 0 ]; then
      ./${file} $1
      ./${file} $1 | grep -A 20 -B 20 "FAIL"
    else
      ./${file} | grep -A 20 -B 20 "FAIL"
    fi
    if [ $? -eq 0 ]; then
      let test_fail_num++
    else
      echo -e "${prefix}${front_green}m  OK${reset}"
    fi
  done # for
  cd ..
  echo -e "${front_green_back_yellow}make all succeeded!(${obj_num}/${test_num})${reset}"
  if [ ${test_fail_num} -ne 0 ]; then
    echo -e "${front_red_back_yellow}test not all succeeded!(failing ${test_fail_num}/${obj_num})${reset}"
  else
    echo -e "${front_green_back_yellow}test all succeeded!(${obj_num}/${obj_num})${reset}"
  fi
else
  echo -e "${front_red_back_yellow}make not all succeeded!(${obj_num}/${test_num})${reset}"
fi

echo "end test ..."
