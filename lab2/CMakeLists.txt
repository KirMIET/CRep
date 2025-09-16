cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем поддиректорию util
add_subdirectory(util)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp)

# Связываем с библиотекой util
target_link_libraries(${PROJECT_NAME} PRIVATE util)