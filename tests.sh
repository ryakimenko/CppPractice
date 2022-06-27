#!/bin/bash

echo "Running tests"
    ./build/debug/test/timeTest && ./build/debug/test/smartptrTest && ./build/debug/test/soundexTest && ./build/debug/test/listTest