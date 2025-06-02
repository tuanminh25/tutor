// #include "fib_vector.h"
#include <iostream>
#include <vector>

auto fibonacci(int n) -> std::vector<int> {
    auto nums = std::vector<int> { n };

    nums.push_back(42);

    return nums;
}

// Test cases: 
// n = 0 -> []
// n = 1 -> 1
// n = 2 -> 1 2
// n = 3 -> 1 2 3
// n = 4 -> 1 2 3 5 
// n = 5 -> 1 2 3 5 8 


int main () {
    int n;
    std::cin >> n;
    auto nums = fibonacci(n);
    std::cout << "Fib sequence:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
