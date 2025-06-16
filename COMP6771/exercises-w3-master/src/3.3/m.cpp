#include "stats.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>


/*
| Operator | Meaning                       | Usage                             |
| -------- | ----------------------------- | --------------------------------- |
| `<<`     | **Stream insertion (output)** | `std::cout << "Hello"`            |
| `>>`     | **Stream extraction (input)** | `std::cin >> x` or `file >> mark` |
*/

/*
For modern C++
- Prefer {} unless you have a specific reason to use ().
- {} is generally safer, clearer, and less error-prone.
 */


auto read_marks(const std::string &path) -> std::vector<int> {
    // this creates a file stream object positioned at the begining of the file
    auto input = std::ifstream{path};

    
    int mark;
    std::vector<int> marks;
    
    // Then from input convert to vector, extract from input
    while (input >> mark) { // read first int and move position forward
    /*
     What counts as whitespace?
        By default:

        Spaces ' '

        Newlines '\n'

        Tabs '\t'

        Carriage return '\r'

        Other standard whitespace characters.
    */
        marks.emplace_back(mark);
    }

    return marks;
}

auto read_marks2(const std::string &path) -> std::vector<int> {
    // Read from file to input
    auto input = std::ifstream{path};

    // vector::vector(InputIt start, InputIt end) constructor is very useful
    return std::vector<int>{
        std::istream_iterator<int>{input}, // iterator at the current point (start)
        std::istream_iterator<int>{} // default constructor -> eof
    };
}

/*
struct stats {
    int avg;
    int median;
    int highest;
    int lowest;
};

*/
auto calculate_stats(const std::vector<int> &marks) -> stats {
    auto sorted_marks = marks;
    std::sort(sorted_marks.begin(), sorted_marks.end());
    return {
        .avg = std::accumulate(marks.begin(), marks.end(), 0) / static_cast<int>(marks.size()), // original val = 0
        .median = sorted_marks[sorted_marks.size() / 2],
        .highest = sorted_marks.back(),
        .lowest = sorted_marks.front(),
    };
}

int main() {
    auto v = read_marks("marks.txt");
    auto v2 = read_marks("marks.txt");

    for (const auto &w : v) {
        std::cout << w << ' ';
    }
    std::cout << '\n';

    for (const auto &w : v2) {
        std::cout << w << ' ';
    }
    std::cout << '\n';


    std::cout << "Mark detail\n";
    std::cout << calculate_stats(v2).avg << '\n';
    std::cout << calculate_stats(v2).median << '\n';
    std::cout << calculate_stats(v2).highest << '\n';
    std::cout << calculate_stats(v2).lowest << '\n';


    return 0;
}