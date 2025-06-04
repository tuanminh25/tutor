#include <iostream>

int main(void) {
    int i = 0;
    int j = 0;

    std::cout << "Please enter two numbers: ";

    if (! (std::cin >> i) || ! (std::cin >> j) ) {
        std::cerr << "Sth wrong: ";
        return -1;
    }
    int sum = i + j;
    std::cout << sum << '\n';
    return 0;
}