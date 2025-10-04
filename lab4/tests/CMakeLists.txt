# Поиск GoogleTest
find_package(GTest REQUIRED)

# Создаем тестовый исполняемый файл
add_executable(iomanipulators_tests
    test_manipulator1.cpp
    test_manipulator2.cpp
    test_manipulator3.cpp
)

target_link_libraries(iomanipulators_tests
    GTest::gtest_main
    iomanipulators
)

# Регистрируем тесты
include(GoogleTest)
gtest_discover_tests(iomanipulators_tests)