cmake_minimum_required(VERSION 3.15)
project(lab4_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_required ON)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(Catch2)

# add_subdirectory(extern/catch2)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(app)