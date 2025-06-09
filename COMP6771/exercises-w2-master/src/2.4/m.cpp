#include "assortment.h"
#include <algorithm>

/*

Input/Output iterators: can only move forward one step at a time, and you can’t reliably go back or revisit elements.

Forward iterators: can move forward repeatedly and revisit elements.

Bidirectional iterators: can move both forward and backward.

Random access iterators: have all bidirectional features plus constant-time jumps anywhere in the sequence (like pointers or vector iterators).

*/

// dynamically resize able at run time, random access iterators
auto sort(std::vector<int> &ivec) -> void {
    // (void)ivec; // remove this when implemented
    std::sort(ivec.begin(), ivec.end());
}

// init size at compile time, can not be resize, random access iterators
auto sort(std::array<int, 4> &iarr) -> void {
    // (void)iarr; // remove this when implemented
    std::sort(iarr.begin(), iarr.end());
}

// dynamically resize able at run time, bidirectional  iterators
auto sort(std::list<int> &ilist) -> void {
    // Compile error to scream
    // std::sort(ilist.begin(), ilist.end());
    // ERROR: std::sort needs random access iterators, but list only has bidirectional
    
    // way 1: use built in list sort
    ilist.sort();

    // way 2: convert data to arr or vector then sort
    auto ivec = std::vector<int>(ilist.begin(), ilist.end());
    std::sort(ivec.begin(), ivec.end());
    std::copy(ivec.begin(), ivec.end(), ilist.begin());

}
