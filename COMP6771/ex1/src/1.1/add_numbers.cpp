#include <iostream>

int main(void) {
    int i = 0;
    int j = 0;

    // printf("Please enter two numbers: ");
    std::cout << "Please enter two numbers: ";

    // std::cin >> i >> j;
    // std::cin >> j;
    if (! (std::cin >> i) || ! (std::cin >> j) ) {
        std::cerr << "Sth wrong: ";
        return -1;
    }
    int sum = i + j;
    std::cout << sum << '\n';
    return 0;
}
