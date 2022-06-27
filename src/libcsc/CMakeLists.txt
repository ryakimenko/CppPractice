include(CompileOptions)

add_library(time STATIC time/time.h time/time.cpp)
add_library(soundex STATIC soundex/soundex.h soundex/soundex.cpp)
add_library(list INTERFACE list/list.h )
add_library(smartptr INTERFACE)

set_compile_options(time)
set_compile_options(soundex)
set_compile_options_interface(list)
set_compile_options_interface(smartptr)

target_include_directories(smartptr INTERFACE
$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/libcsc/smartptr>
$<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/build/src/libcsc
)

add_executable(sounedxApp soundex/main.cpp)
set_compile_options(sounedxApp)
target_link_libraries(sounedxApp PRIVATE soundex)
target_link_libraries(sounedxApp PRIVATE nlohmann_json::nlohmann_json)