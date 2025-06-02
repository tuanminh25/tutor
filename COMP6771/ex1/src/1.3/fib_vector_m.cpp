#include <iostream>
#include <vector>


auto fibonacci1(int n) -> std::vector<int> {
    auto nums = std::vector<int> {};
    int step = 0;
    for (int k_1 = 0, k_2 = 1; step < n; ++step) {
        int k_th = k_1 + k_2;
        nums.push_back(k_th);
        k_1 = k_2;
        k_2 = k_th;
    }
    return nums;
}

auto fibonacci2(int n) -> std::vector<int> {
    auto nums = std::vector<int> {};

    // edge case
    if (n <= 0) return nums;

    // case size 1
    nums.push_back(1);
    if (n == 1) return nums;

    // case size 2+
    nums.push_back(1);
    for (int k1 = 0, k2 = 1; n > 0; --n) {
        int val1 = nums[k1];
        int val2 = nums[k2];

        nums.push_back(val1 + val2);
        k1 ++;
        k2 ++;

    }
    return nums;
}

auto fibonacci3(int n) -> std::vector<int> {
   auto nums = std::vector<int>{};
    if (n <= 0) return nums;

    nums.push_back(0);
    if (n == 1) return nums;

    nums.push_back(1);
    for (int i = 2; i < n; ++i) {
        nums.push_back(nums[i - 1] + nums[i - 2]);
    }
    return nums;
}


// Test cases: 
// n = 0 -> []
// n = 1 -> 1
// n = 2 -> 1 2
// n = 4 -> 0, 1, 1, 2
// n = 13 -> 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

int main () {
    int n;
    std::cin >> n;
    auto nums = fibonacci2(n);
    std::cout << "Fib sequence:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
