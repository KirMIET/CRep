# Создаем библиотеку из исходных файлов
add_library(util STATIC
    util.cpp
    util.h
)

# Указываем, что заголовочные файлы являются публичными
target_include_directories(util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})