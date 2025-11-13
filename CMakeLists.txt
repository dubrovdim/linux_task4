cmake_minimum_required(VERSION 3.20)
project(cmake_vs_mkr_test1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Директорії
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_SRC_DIR     ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_TEST_DIR    ${CMAKE_SOURCE_DIR}/tests)

add_executable(test_repos
  ${PROJECT_SRC_DIR}/pch.cpp
  ${PROJECT_SRC_DIR}/stringProcessor.cpp
  ${PROJECT_SRC_DIR}/sort.cpp
  ${PROJECT_TEST_DIR}/test.cpp
)

target_include_directories(test_repos PRIVATE ${PROJECT_INCLUDE_DIR})

if (MSVC)
  target_compile_options(test_repos PRIVATE /W4 /permissive-)
  target_precompile_headers(test_repos PRIVATE ${PROJECT_INCLUDE_DIR}/pch.h)
else()
  target_compile_options(test_repos PRIVATE -Wall -Wextra -Wpedantic)
  # PCH під GCC не обов’язковий; "pch.h" просто інклудиться у test.cpp
endif()

# -------- GoogleTest через FetchContent (НІЯКОГО find_package тут) --------
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# Для MSVC – одна CRT; під GCC не заважає
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_repos PRIVATE gtest gtest_main)

# Тести + XML для Jenkins
enable_testing()
add_test(NAME all_tests
  COMMAND test_repos --gtest_output=xml:${CMAKE_BINARY_DIR}/test_report.xml)
