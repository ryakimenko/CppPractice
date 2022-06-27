#!/bin/bash

readonly scriptdir="$(dirname "$(readlink -f "$0")")"
readonly debug_dir=$scriptdir/build/debug
readonly release_dir=$scriptdir/build/release

#git submodule init
#git submodule update

echo "Building Debug"
cmake -S $scriptdir -B $debug_dir -DTIDY=ON -DCMAKE_BUILD_TYPE=Debug \
    && cmake --build $debug_dir

#echo -e "Building Release"
#cmake -S $scriptdir -B $release_dir -DTIDY=ON -DCMAKE_BUILD_TYPE=Release \
#    && cmake --build $release_dir