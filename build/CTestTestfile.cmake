# CMake generated Testfile for 
# Source directory: C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1
# Build directory: C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[all_tests]=] "C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1/build/test_repos.exe" "--gtest_output=xml:C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1/build/test_report.xml")
set_tests_properties([=[all_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1/CMakeLists.txt;45;add_test;C:/Users/Dmytro/Desktop/linux_cursova/task4_test/cmake_vs_mkr_test1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
