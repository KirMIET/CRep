cmake_minimum_required(VERSION 3.10)
project(lab5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 REQUIRED)

include_directories(include)

add_executable(tests tests/proxy.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

find_package(Threads REQUIRED)
target_link_libraries(tests PRIVATE Threads::Threads)

enable_testing()

include(Catch)
catch_discover_tests(tests)