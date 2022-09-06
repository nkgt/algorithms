cmake_minimum_required(VERSION 3.23)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

include(cmake/compiler.cmake)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

list(APPEND algorithms_SOURCES
    src/sorting.cpp
)

list(APPEND algorithms_INCLUDES
    include/nkgt/algorithms/sorting.hpp
)

add_library(algorithms STATIC
    ${algorithms_SOURCES}
    ${algorithms_INCLUDES}
)

target_include_directories(algorithms PUBLIC include)
target_link_libraries(algorithms PRIVATE fmt::fmt spdlog::spdlog)

set_compiler_options(algorithms)
set_warnings(algorithms)

if(NKGT_ALGO_TESTS)
    add_subdirectory(test)
endif()

# if(NKGT_ALGO_BENCH)
#     add_subdirectory(benchmark)
# endif()