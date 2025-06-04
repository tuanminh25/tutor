#include "setdiff.h"

#include <algorithm>
#include <vector>

auto set_difference(std::vector<char> &vec_set, const std::vector<char> &blacklist) -> void {
    // (void)vec_set;
    // (void)blacklist;
    // std::string
    for (const auto &c : blacklist) {
        std::erase(vec_set, c);
    }
}
