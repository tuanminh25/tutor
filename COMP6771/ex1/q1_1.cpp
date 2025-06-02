#include <iostream>

// Q1.1. Your first C++ Program (compared to your first C program)

/*
    std::cin >> i - read in
    std::cout >> print out to standard output 
    std::cerr >> print out to standard error 
    
*/
int main () {
    auto i = 0;
    if (not (std::cin >> i)) {
        std::cerr << "Something went wrong while reading an integer, bailing...\n";
        return 1;
    }

    std::cout << "Value of i: " << i << '\n';

}