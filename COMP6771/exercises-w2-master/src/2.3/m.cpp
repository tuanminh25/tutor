#include "permutation.h"

#include <algorithm>
#include <unordered_map>

/*
A permutation is a rearrangement of elements in a set.

In the context of strings, 
one string is a permutation of another if both contain the same characters with the same frequencies, 
but possibly in a different order.

ie
abc is permutation with bca 
abc is not permutation with bcd 


*/

auto sort_compare(const std::string &x, const std::string &y) -> bool {
    std::string sorted_x = x;
    std::string sorted_y = y;

    std::sort(sorted_x.begin(), sorted_x.end());
    std::sort(sorted_x.begin(), sorted_x.end());

    return sorted_x == sorted_y;
}


auto frequencies_map(const std::string &x) -> std::unordered_map<int, char> {
    std::unordered_map<int, char> map_m;

    // for map x
    for (const auto &c : x) {
        if (map_m.find(c) == map_m.cend()) {
            map_m.emplace(c, 1);
            // map_x[c] = 1;
        } else {
            ++map_m[c];
        }

    }

    return map_m;
}



auto is_permutation(const std::string &x, const std::string &y) -> bool {
    if (x.size() != y.size()) {
        return false;
    }

    // generate 2 frequencies map  or 
    return frequencies_map(x) == frequencies_map(y);

    // sort and compare
    return sort_compare(x, y);
}
