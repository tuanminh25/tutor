#include "invert.h"
#include <map>
#include <iterator>
#include <iostream>



auto invert(const std::map<std::string, int> &mp) -> std::map<int, std::string> {
    std::map<int, std::string> inverted;
    
    for(const auto &[key, val] : mp) {
        // Check if exist or not
        auto it = inverted.find(val);

        if (it == inverted.end()) {
            // Add new
            inverted.insert({val, key});
        } else {
            // Compare size: current key and stored val
            if (it->second.size() < key.size()) {
                inverted[val] = key;
            } 
            
        }

    }

    return inverted;
}

int main () {
    auto data = std::map<std::string, int>{
        {"a", 6771},
        {"ab", 6771},
        {"abc", 6771},
        {"xyz", 6772},
    };
    auto expected = std::map<int, std::string>{
        {6771, "abc"},
        {6772, "xyz"},
    };

    auto actual = invert(data);

    std::cout << (actual == expected) << '\n';
}