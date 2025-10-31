# CMake generated Testfile for 
# Source directory: /workspaces/CRep/lab6
# Build directory: /workspaces/CRep/lab6/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IteratorTests "/workspaces/CRep/lab6/build/iterator_tests")
set_tests_properties(IteratorTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/CRep/lab6/CMakeLists.txt;29;add_test;/workspaces/CRep/lab6/CMakeLists.txt;0;")
subdirs("_deps/catch2-build")
