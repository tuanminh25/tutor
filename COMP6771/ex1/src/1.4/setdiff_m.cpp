#include "setdiff.h"

#include <algorithm>
#include <vector>

auto set_difference(std::vector<char> &vec_set, const std::vector<char> &blacklist) -> void {
    // Loop through each item in vec_set
    // Check if that item belongs in the blacklist or not
    // If yes -> remove 
    
    // 1 - deal right on the same vector
    for (auto &c : blacklist) {
        std::erase(vec_set, c);
    }


    // 2 
    for (char c : blacklist) {
        // manually remove all occurrences of c from vec_set
        auto it = vec_set.begin();
        while (it != vec_set.end()) {
            if (*it == c) {
                it = vec_set.erase(it); // erase returns next valid iterator
            } else {
                ++it;
            }
        }
    }
}
