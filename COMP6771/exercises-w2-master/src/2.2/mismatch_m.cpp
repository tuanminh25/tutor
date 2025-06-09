#include <utility>
#include <vector>

#include "mismatch.h"

/*
I. Standard Template Library (aka the STL, now part of the C++ standard proper)
- containers: store collection data
- iterators: traversal through those containers having data
- algorithm: operation on those data


II. Iterators

v = 1 2 3 4 5
    ^         ^
    |         |
v.begin()    v.end() - past the last element


An iterator in C++ is an object that allows you to traverse a container

*/

/*

std::mistmatch
Returns a pair of iterators to the first mismatching of elements from [first1, last1) and a range
starting from first2:

equivalent to: typedef typename std::vector<int>::iterator iter;
using iter = typename std::vector<int>::iterator;

*/

auto mismatch(std::vector<int>& v1, std::vector<int>& v2) -> std::pair<iter, iter> {
	auto iter1 = v1.begin();
	auto iter2 = v2.begin();

	auto last1 = v1.end();
	auto last2 = v2.end();

	while (iter1 != last1 && iter2 != last2 && *iter1 == *iter2) {
		++iter1;
		++iter2;
	}

	return std::make_pair(iter1, iter2);
}
