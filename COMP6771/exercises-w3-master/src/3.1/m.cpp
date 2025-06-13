#include "sort_descending.h"
/*

std::greater<>{} -  function object (functor) from <functional>

+ a comparison object that returns true 
if the first argument is greater than the second

+ can be used in sort

Why {}? std::greater<> is a class template.

{} creates a default-constructed instance.

It’s the same as writing:

    std::greater<int> comp;
    std::sort(v.begin(), v.end(), comp);


*** Extra note ***
But std::greater<>{} uses CTAD (Class Template Argument Deduction), 
so you don't need to specify <int>.
*/

auto sort_descending(std::vector<int> &numbers) -> void {
    std::sort(numbers.begin(), numbers.end(), std::greater<>{})
}
