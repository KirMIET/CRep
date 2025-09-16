cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем все исходные файлы
add_executable(${PROJECT_NAME}
    main.cpp
    util/util.cpp
    util/util.h
)

# Указываем путь к заголовочным файлам
target_include_directories(${PROJECT_NAME} PRIVATE util)