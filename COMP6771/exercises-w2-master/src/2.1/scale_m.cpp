#include "scale.h"

// what is static and dynamic cast?


// use static_cast to change from vec int to vec double, 
// each of the int in vector, mul it with factor

// default value of 0.5 for the scaling factor
// auto scale(std::vector<int> &ivec, double factor = 0.5) -> std::vector<double>;

auto scale(std::vector<int> &ivec, double factor) -> std::vector<double> {
    std::vector<double> v;

    for (auto &i : ivec) {
        auto new_d = static_cast<double>(i) * factor;
        v.emplace_back();
    }

    return {};
}
