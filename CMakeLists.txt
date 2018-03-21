cmake_minimum_required(VERSION 3.9)

add_library(box INTERFACE)
target_include_directories(box INTERFACE include/)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(box_test test/test.cc)

target_link_libraries(box_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
target_link_libraries(box_test box)
