#include <iostream>

// reads in two integers and prints out their sum.
int main(void) {
    int i, j;

    // Read in
    if (not (std::cin >> i) || not (std::cin >> j)) {
        std::cerr << "Something went wrong while reading an integer, bailing...\n";
        return 1;
    }

    // std::cin >> i;
    // std::cin >> j; 

    // Calculate sum 
    int sum = i + j;

    // Print out sum
    std:: cout << sum << "\n"; // operator chaining

    return 0;
}
