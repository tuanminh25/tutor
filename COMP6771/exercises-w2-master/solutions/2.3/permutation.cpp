#include "permutation.h"

#include <unordered_map>

auto count_letters(std::string const &x) -> std::unordered_map<char, int> {
	auto dictionary = std::unordered_map<char, int>();

	for (const auto letter : x) {
		auto result = dictionary.find(letter);
		if (result == dictionary.cend()) {
			dictionary.emplace(letter, 1);
			continue;
		}
		++result->second;
	}

	return dictionary;
}

auto is_permutation(const std::string &x, const std::string &y) -> bool {
	return count_letters(x) == count_letters(y);

	// alternatively
	std::string x_to_sort = x;
	std::string y_to_sort = y;
	std::sort(x_to_sort.begin(), x_to_sort.end());
	std::sort(y_to_sort.begin(), y_to_sort.end());
	return x_to_sort == y_to_sort;
}
