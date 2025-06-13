#include "vowel_sort.h"
/*
lambda function = anonymous function you 
+ can declare inline 
+ function without a name.
+ can be redefined many time in a scope 
+ convininet ish kinda of thing

formula:
put in external values
   |
   |      values passed when call this function
   v         v
[capture](parameters) -> return_type {
    function_body
}

*/

auto vowel_sort(std::vector<std::string> &vs) -> void {
  std::sort(vs.begin(), vs.end(), [](const std::string &x, const std::string &y) {
	const auto vowels = [](char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	};

    auto xcount = std::count_if(x.cbegin(), x.cend(), vowels);
    auto ycount = std::count_if(y.cbegin(), y.cend(), vowels);
	
//     If xcount == ycount is true → return x < y
// Otherwise → return xcount < ycount
	return xcount == ycount ? x < y : xcount < ycount;
  });
}
