#include "catch2/catch_test_macros.hpp"
#include "catch2/generators/catch_generators_adapters.hpp"
#include "catch2/generators/catch_generators_random.hpp"
#include "catch2/matchers/catch_matchers_vector.hpp"

#include "nkgt/algorithms/sorting.hpp"

#include <algorithm>
#include <vector>

struct Range {
    int min;
    int max;
};

std::vector<int> generate_random_vector(std::size_t size, Range range) {
    return Catch::Generators::chunk(size, Catch::Generators::random(range.min, range.max)).get();
}

TEST_CASE("Insertion Sort - Sort random vector passed by copy", "[insertion-sort]") {
    std::vector<int> v = generate_random_vector(100, { 0, 999999 });
    
    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());

    auto sorted = nkgt::algorithms::sorting::insertion_sort(v);

    REQUIRE_THAT(
        sorted,
        Catch::Matchers::Equals(expected)
    );
}

TEST_CASE("Insertion Sort - Sort empty vector passed by copy", "[insertion-sort]") {
    std::vector<int> v {};
    std::vector<int> expected {};

    auto sorted = nkgt::algorithms::sorting::insertion_sort(v);

    REQUIRE_THAT(
        sorted,
        Catch::Matchers::Equals(expected)
    );
}

TEST_CASE("Insertion Sort - Sort one element vector passed by copy", "[insertion-sort]") {
    std::vector<int> v { 1 };
    std::vector<int> expected { 1 };

    auto sorted = nkgt::algorithms::sorting::insertion_sort(v);

    REQUIRE_THAT(
        sorted,
        Catch::Matchers::Equals(expected)
    );
}

TEST_CASE("Insertion Sort - Sort random vector passed by span", "[insertion-sort]") {
    std::vector<int> v = generate_random_vector(100, { 0, 999999 });

    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());

    nkgt::algorithms::sorting::insertion_sort(std::span{ v.begin(), v.size() });

    REQUIRE_THAT(
        v,
        Catch::Matchers::Equals(expected)
    );
}

TEST_CASE("Insertion Sort - Sort empty vector passed by span", "[insertion-sort]") {
    std::vector<int> v {};
    std::vector<int> expected {};

    nkgt::algorithms::sorting::insertion_sort(std::span{ v.begin(), v.size() });

    REQUIRE_THAT(
        v,
        Catch::Matchers::Equals(expected)
    );
}

TEST_CASE("Insertion Sort - Sort one element vector passed by span", "[insertion-sort]") {
    std::vector<int> v { 1 };
    std::vector<int> expected { 1 };

    nkgt::algorithms::sorting::insertion_sort(std::span{ v.begin(), v.size() });

    REQUIRE_THAT(
        v,
        Catch::Matchers::Equals(expected)
    );
}