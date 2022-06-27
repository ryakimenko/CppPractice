cmake_minimum_required(VERSION 3.1)

project(cpp-labs-spring)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_program(
  CLANG_TIDY_EXE
  NAMES clang-tidy-10 clang-tidy
)

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)