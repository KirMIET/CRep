cmake_minimum_required(VERSION 3.14)
project(ManipulatorsProject)

set(CMAKE_CXX_STANDARD 17)

# Автоматическая загрузка GoogleTest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG release-1.12.1
# )
# FetchContent_MakeAvailable(googletest)

# Основная библиотека с манипуляторами
add_library(iomanipulators
    src/manipulator1.cpp
    src/manipulator2.cpp
    src/manipulator3.cpp
)

target_include_directories(iomanipulators 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ДЕМОНСТРАЦИОННАЯ ПРОГРАММА
add_executable(${PROJECT_NAME} app/main.cpp)
target_link_libraries(${PROJECT_NAME} iomanipulators)

# ТЕСТЫ
# enable_testing()
# add_executable(${PROJECT_NAME}_tests
#     tests/test_manipulator1.cpp
#     tests/test_manipulator2.cpp
#     tests/test_manipulator3.cpp
# )

add_executable(${PROJECT_NAME}_tests
    tests/test_global.cpp
)

target_link_libraries(${PROJECT_NAME}_tests
    iomanipulators
    catch
)

enable_testing()
add_test(${PROJECT_NAME}_tests ${PROJECT_NAME}_tests)

# target_link_libraries(${PROJECT_NAME}_tests
#     GTest::gtest_main
#     iomanipulators
# )

# include(GoogleTest)
# gtest_discover_tests(${PROJECT_NAME}_tests)