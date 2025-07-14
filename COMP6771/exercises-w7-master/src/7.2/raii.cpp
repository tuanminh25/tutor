#include <iostream>
#include <memory>

// RAII -> Resource Acquisition Is Initialization (design pattern in C++)
// Resources should be tie with object
// Object is freed -> resources should be gone as well

struct data {
    data(int n) : number_{std::make_unique<int>(n)} {}

    ~data(void) = default;

    std::unique_ptr<int> number_;
};

auto demo(void) -> void {
    // the data constructor calls make_unique which allocates heap memory for the number_ member
    auto territories = data(2);
    // this line doesn't do any heap memory management
    std::cout << "there are " << territories.number_.operator*() << " territories in the Commonwealth of Australia\n";
    /**
        * we have reached the end of the scope
        * in practical terms this is the line before the most-indented closing brace ('}')
        * the compiler will call the destructor for data on territories
        * the destructor for std::unique_ptr is called and now the number_ member is freed
        * the compiler will call the destructor for data on territories
    */
}

auto main(void) -> int {
    demo();
    return 0;
}
