// #include "fib_vector.h"
#include <iostream>
#include <vector>

auto fibonacci(int n) -> std::vector<int> {
    auto nums = std::vector<int> {};

    // nums.push_back(42);
    
    //  n <= 0
    if (n <= 0) {
        return nums;
    }

    // n == 1
    nums.push_back(1);
    // nums.emplace_back(1);
    if (n == 1) {
        return nums;
    }

    // n > 1
    nums.push_back(1);

    for (int i = 2; i < n; ++i) {
        nums.push_back(nums[i-1] + nums[i-2]);
    }

    return nums;
}

// Test cases: 
// n = 0 -> []
// n = 1 -> 1
// n = 2 -> 1 1
// n = 3 -> 1 1 2 
// n = 4 -> 1 1 2 3  
// n = 5 -> 1 1 2 3 5  

// 1 1 2 3  

int main () {
    int n;
    std::cin >> n;
    auto nums = fibonacci(n);
    std::cout << "Fib sequence:\n";

    // ++i;
    // i++;


    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << ' ';
    }
    
    std::cout << '\n';
    
    // std::cout << nums[-1] << '\n';
    std::cout << nums.at(-2) << '\n';

    return 0;
}
