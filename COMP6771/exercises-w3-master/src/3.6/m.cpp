#include "./dict.h"
#include <iterator>
#include <algorithm>
#include <iostream>

#include <istream>
#include <string>
#include <vector>
#include <sstream>
auto to_word_list(std::istream &input) -> std::vector<std::string> {
    return {std::istream_iterator<std::string>{input}, std::istream_iterator<std::string>{}};
}

/*
std::ostream_iterator<std::string>{output, " "}
This is the output iterator.
Every time std::copy_if writes something, it writes it to output followed by a " " (space separator).
So: valid words are printed to output, separated by spaces.

[&]: captures everything that exists at the point where you write the lambda.
*/

auto print_valid_words(
    const std::vector<std::string> &valid_words,
    std::istream &input,
    std::ostream &output
) -> void {
    std::copy_if(
        std::istream_iterator<std::string>{input},
        std::istream_iterator<std::string>{},
        std::ostream_iterator<std::string>{output, " "},
        [&valid_words](const std::string &s) {
            auto found_word = std::find(valid_words.begin(), valid_words.end(), s); 
            return found_word != valid_words.end();
        }
    );

}

int main () {
    std::string input = "hello world haha";
    std::istringstream input_buffer{input};
    std::ostringstream output_buffer; // buffer holding a string
    print_valid_words({"hello", "world"}, input_buffer, output_buffer);
    std::cout << output_buffer.str() << '\n';
    return 0;
}