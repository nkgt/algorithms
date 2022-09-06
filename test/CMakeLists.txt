enable_testing()

find_package(Catch2 CONFIG REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(algorithms-tests sorting.cpp)

target_link_libraries(algorithms-tests
PRIVATE algorithms
PRIVATE Catch2::Catch2WithMain
)

set_compiler_options(algorithms-tests)
set_warnings(algorithms-tests)

catch_discover_tests(algorithms-tests)