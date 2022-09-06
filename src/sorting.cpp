#include "nkgt/algorithms/sorting.hpp"
//#include <limits>
//
//template<typename T>
//std::vector<T> nkgt::algorithms::sorting::insertion_sort_copy(std::vector<T> v) noexcept {
//    if(v.empty() || v.size() == 1) {
//        return v;
//    }
//
//    for(int i = 1; i < v.size(); ++i) {
//        const int key = v[i];
//        auto j = i - 1;
//
//        while (j >= 0 && v[j] > key) {
//            v[j + 1] = v[j];
//            j -= 1;
//        }
//
//        v[j + 1] = key;
//    }
//
//    return v;
//}