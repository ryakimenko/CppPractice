include(CompileOptions)

set(timeTest timeTest)
set(smartptrTest smartptrTest)
set(soundexTest soundexTest)
set(listTest listTest)

add_executable(${timeTest} libcsc/time.cpp)
add_executable(${smartptrTest} libcsc/smartptr.cpp)  
add_executable(${soundexTest} libcsc/soundex.cpp)
add_executable(${listTest} libcsc/list.cpp)    

set_compile_options(${timeTest})
set_compile_options(${smartptrTest})
set_compile_options(${soundexTest})
set_compile_options(${listTest})

target_link_libraries(${timeTest} PRIVATE time gtest)
target_link_libraries(${smartptrTest} PRIVATE smartptr gtest)
target_link_libraries(${soundexTest} PRIVATE soundex gtest)
target_link_libraries(${listTest} PRIVATE list gtest)


target_include_directories(${timeTest} PRIVATE ${CMAKE_SOURCE_DIR}/src/libcsc/)
target_include_directories(${smartptrTest} PRIVATE ${CMAKE_SOURCE_DIR}/src/libcsc/)
target_include_directories(${soundexTest} PRIVATE ${CMAKE_SOURCE_DIR}/src/libcsc/)
target_include_directories(${listTest} PRIVATE ${CMAKE_SOURCE_DIR}/src/libcsc/)