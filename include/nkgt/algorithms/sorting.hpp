#pragma once

#include <span>
#include <vector>

namespace nkgt::algorithms::sorting
{

template<typename T, std::size_t N>
constexpr void insertion_sort(std::span<T, N> s) {
    for (int i = 1; i < s.size(); ++i) {
        const int key = s[i];
        auto j = i - 1;

        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j -= 1;
        }

        s[j + 1] = key;
    }
}

template<typename T>
constexpr std::vector<T> insertion_sort(std::vector<T> v) {
    insertion_sort(std::span{ v.begin(), v.size() });
    return v;
}

}
