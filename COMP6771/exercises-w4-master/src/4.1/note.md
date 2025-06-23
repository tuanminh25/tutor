remember to run: 

clang-format -i {path} # -i is inplace, without this, formatted code will be printed to stdout

# 4.1.1 Implementation Issues

## 2.1. Miscellaneous

No issues.


## 2.2. Comments

There is commented out code in the implementation of `first`.

```cpp
auto xector::first() -> std::optional<std::string> {
    // TODO: test if this is needed
    // if (items_.empty()) {
    //     return std::nullopt;
    // }
```

Your assignment represents a final piece of completed work, intended to be reviewed and run.  
It is better to delete incomplete code before final submission.

===============================================================

Try to avoid comments that do not offer more meaningful insight than code itself.  
In the `size` method there is a direct translation of what the `++` operator does.


===============================================================


It is okay to explain code in comments if it introduces extra context to the reader that might not be immediately obious.  
For example in the `string_contains_special` helper method.

```cpp
    // .find returns the constant npos if the character was not found
    return s.find(SPECIAL_LETTER) != std::string::npos;
```



##  2.3. Custom Containers

### Not Using `algorithm`

Avoid "reinventing the wheel" and try use a method from `<algorithm>` if one exists for standard loop patterns:

- it makes your code clearer;
- you are forced to account for out-of-scope variables in the lambda capture;
- you write fewer lines of code.

The `first` method could have been implemented using `std::find_if`.  
This is demonstrated in its mirror method `last`.

The `size` method could have been implemented with `std::count_if`.

```cpp
size_t xector::size() {
    return std::count_if(items_.begin(), items_.end(), string_contains_special)
}
```



## 2.4. Avoiding C-style

### Index-Based Loops

The `size` method contains an unnecessary index-based loop that we would use from traditional C.

```cpp
    for (size_t i = 0; i < items_.size(); ++i) {
        auto curr = items_.at(i);
        if (string_contains_special(curr)) {
            // add one to the result if we found a matching character
            ++result;
        }
    }
}
```

The only use of the index variable `i` is to access the `items_` member at the particular index.  
In these cases, it is better to use a range-based loop and adjust the `const` and reference-semantics to the use case.

```cpp
    for (auto const &curr : items_) {
        if (string_contains_special(curr)) {
            ++result;
        }
    }
```

If you need to do calculations with the index \(eg. get index `i - i`\) or anything other than just accessing the element at index, it is then okay to use an index-based loop.

### Constants

There is a #defined constant, that should have been a class-level constant.

```cpp
#define SPECIAL_LETTER 'x'
```

Following modern C++ principles, it is better to use a `const` variable rather than a C-style `#define` preprocessing directive as:

- it provides type safety;
- the `const` keyword communicates the immutable nature of the constant.

```cpp
char const SPECIAL_LETTER = 'x'
```




## 2.5. Using Modern C++

### Prototypes Mixing `auto` and Defined Types

The prototypes for `.size` and `.first` mix between defined types and `auto`.

```cpp
size_t size();
auto first() -> std::optional<std::string>;
```

You are free to pick between either defined types or `auto`, but do not mix between the two.  
Hence, either of these would have been better \(this applies to all other class methods\):

```cpp
auto size() -> size_t;
auto first() -> std::optional<std::string>;
```

```cpp
size_t size();
std::optional<std::string> first();
```

### Reference Semantics

Avoid copy-constructing variables unless you need to.

The `string_contains_special` helper function will create a copy of the original parameter when passed as argument.

```cpp
auto string_contains_special(std::string const s) -> bool;
```

The function only reads the string, so there is no need for this.  
Hence, it would be better to pass the parameter by reference.

```cpp
auto string_contains_special(std::string const &s) -> bool;
```

The same point can also be made about the `curr` variable previously mentioned in index-based looping in the `size` function.  
So we should prefer:

```cpp
        auto curr = items_.at(i);
```

to

```cpp
    for (auto const &curr : items_) {
```

or auto &curr = items_.at(i);
.

### `const` Correctness

The following methods should have been marked as `const`, since they should work on an `xector` marked as `const`.

```cpp
auto size() const -> size_t; // const member function -> does not modify member variable
auto first() const -> std::optional<std::string>; // const member function -> does not modify member variable
auto last() const -> std::optional<std::string>; // const member function -> does not modify member variable
```

/*
A member function is defined inside a class, and has access to the class’s internal state

A non-member function is defined outside the class, and takes objects as parameters (usually by reference or pointer).

*/

Akin to JavaScript, if you are not sure, it is best to start by marking methods and variables as `const` and then removing this later if the implementation requires it.

### Anonymous Namespaces or Private Methods

Helper functions have not been written in an anonymous namespace in the `.cpp` file and are just in the top level of the `.h` file.

```cpp
/**
    0. HELPER METHODS
 */

auto string_contains_special(std::string const &s) -> bool;
```

Helpers should be written in anonymous namespace in a `.cpp` file so that they are not accessible from the public interface

```cpp
namespace {
    auto string_contains_special(std::string const &s) -> bool;
}
```

It would have also been okay to write them as class methods marked as `private`.  
This is the preferred method if you are implementing a class in the `.h` file or a `.hpp` file.

## Class Types

These issues relate more broadly to the topic of best practices in C++ classes.

### `default`

The no-arg `xector` constructor should be marked as `default`.  
We can let the compiler create all members by using their respective default constructors per type.

```cpp
xector::xector() = default
```

### Delegating Constructors

Constructor code is often repeated.  
We strongly encourage you to delegate to other constructors where possible.

The following delegation could have been made in the `xector` constructors.

```cpp
xector::xector(std::vector<std::string>::const_iterator start, std::vector<std::string>::const_iterator end) : items_{start, end} {}
xector::xector(std::vector<std::string> const &items) : xector(items.begin(), items.end()) {}
```

As a side note, a very common pattern is to have:

1. a \(\[n\] often private\) constructor that can directly initialise all members;
2. then have most other constructors delegate to that one.

This is a modified example taken from a past lecture.

```cpp
class dummy {
public:
    // only one exposed constructor that sets the value to 0
    dummy() : dummy(0) {}
private:
    int val_;

    // this private constructor accepts values for all members
    dummy(int val) : val_{val} {}
};

```

### Member Initialiser List

You should not initialise a member inside the body of a constructor.  
Initialise in the member initialiser list of the constructor.

In the `std::initializer_list` constructor, `items_` has been re-initialised in the body.

```cpp
xector::xector(std::initializer_list<std::string> items) {
    items_ = std::vector<std::string>();
```

In this case, the entire body of the function is not necessary and all the logic can be done in the member initialiser list.

```cpp
xector::xector(std::initializer_list<std::string> items) : items_{items.begin(), items.end()} {}
```

A(int a, int b) : a_(a), b_(b) {}

This has also been shown in the constructor taking in a `std::vector<std::string>::const_iterator` range.

It is quite common for a class to have most constructors with empty implementation bodies.  
Try to do as much work as you can using:

1. member initialiser lists;
2. delegating constructors.



# 4.1.2 Testing Issues

## Correctness

No issues.

## Coverage

### Edge Cases

Edge cases have not been covered:

1. `first` and `last` when no elements contain an `'x'`;
2. constructing with an empty `std::vector`.

### `const` Objects

No testing has been conducted using `xector`s marked as `const`.  
In this case, it would have revealed issues with `const`-correctness as an `xector` marked as `const` will not be able to access:

1. `size`;
2. `first` and `last`;

which all **do not** modify the original `xector` \(as per the spec\).

This is a very common method to reason about which methods should:

- be marked as `const`;
- or require a `const` overload.

## Brittleness

### Testing Helpers

There is a test for the helper function `string_contains_special`.

```cpp
TEST_CASE("checking helper function string contains") {
```

Helper functions are not defined by a public interface and should not be directly tested.  
Aim to test your helpers by calling other public interface methods.  
If you cannot call helpers through public interface methods, this is a sign that your helpers can never be actually called.

This also relates to a style issue, as the helper function must be exposed in the `.h` file, which conflicts with the requirement that they be written in an anonymous namespace of a `.cpp` file.

As a caveat, it is okay to conduct your own private testing, so long as this is not committed and submitted into your final assignment code.

## Clarity

### Order

Constructors should always be tested first.  
Then, tests should be written in order of increasing complexity:

- happy cases should come first;
- simpler functions call fewer other functions.

Currently, the testing order is scrambled:

1. it begins with a complex test;
2. constructors are written last.

### Veracity

You should be able to clearly verify the expected answer of a test.

```cpp
TEST_CASE("complex example") {
    // there is an x somewhere in this string
    auto xec = xector{"aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffkkkkkkldsjkfewjrbhjjregbreoijreioxkljdfjkhkjbbbbbboioioerjhgioeriouioqw"};
    CHECK(xec.size() == 1);
}
```

In this test case, it is very hard to find the `'x'` character and know that there should be one item considered by the `xector`.  
Avoid large inputs for which it is hard to verify the expected result.  
Such inputs should be left to either benchmarking or stress-testing \(we do not expect you to conduct these unless otherwise stated\), rather than unit and integration tests:

### Compile-Time Verification

Avoid any code that is runtime-reliant.  
At compile time, you should be able to look at a test and understand each test.

This test relies on a random index, to be generated at runtime.

```cpp
TEST_CASE("comprehensive runtime-verified test") {
    // all of these items should be considered by the xector
    auto good = std::vector<std::string>{"xray", "extreme", "duplex", "blaxland"};

    // pick a random index to check - any of them should work
    auto choice = pick_random_number(good.size());
    auto xec= xector{good.at(choice)};
    CHECK(xec.size() == 1);
}
```

This means that at compile time, you cannot know which of the inputs where picked, and hence verify that they each work.

It is better to explicitly check that all `good` inputs correctly get seen by the `xector`.  
The test after tries to do this with a loop.

```cpp
TEST_CASE("checking many individual correct strings") {
    auto good = std::vector<std::string>{"xray", "extreme", "duplex", "blaxland"};

    auto xec = xector();
    for (auto const& g : good) {
        xec.push_back(g);
        CHECK(xec.last() == g);
    }
}
```

It is better to manually iterate yourself through otherwise-looped inputs, so it is clear where exactly tests fail.

```cpp
TEST_CASE("checking many individual correct strings") {
    auto good = std::vector<std::string>{"xray", "extreme", "duplex", "blaxland"};
    auto xec = xector();

    xec.push_back("xray");
    CHECK(xec.last() == "xray");

    xec.push_back("extreme");
    CHECK(xec.last() == "extreme");

    // ... continue for all other items
```

So for example, if the test is to fail then we can clearly identify `"xray"` was the source of the buggy input, or `"extreme"`, etc.

### Testing Multiple Non-Related Things

This test case tests two different constructors in one single `TEST_CASE`.

```cpp
TEST_CASE("") {
    // CONSTRUCTOR USING VECTOR
    auto items = std::vector<std::string>{"xdisregard", "climb", "axel", "apex", "xdisregard"};

    // ...

    // NOW ANOTHER UNRELATED CONSTRUCTOR IS TESTED

    // now test the full vector
    auto xec_default = xector(items);
    CHECK(xec_default.size() == 4);
}
```

Ensure that only one thing is tested per test.  
We should break up the test into to `TEST_CASE`s.

```cpp
TEST_CASE("xector constructed from std::vector range") {}
TEST_CASE("xector constructed from std::vector") {}
```

## Simplicity

### Helper Functions in Testing

This test calls a testing-helper function `pick_random_number`.

```cpp
TEST_CASE("comprehensive runtime-verified test") {
    // all of these items should be considered by the xector
    auto good = std::vector<std::string>{"xray", "extreme", "duplex", "blaxland"};

    // pick a random index to check - any of them should work
    auto choice = pick_random_number(good.size());
```

This is a sign that the test is too complicated and should be simplified.

## Catch2

These issues relate to not following Catch2 guidelines.

### Using Proper Macros

```cpp
TEST_CASE("checking helper function string contains") {
    // ...

    CHECK(not string_contains_special("jaime"));
}
```

Use macros like `CHECK_FALSE` rather than inverting booleans, when expecting a `false` value.

```cpp
TEST_CASE("checking helper function string contains") {
    // ...

    CHECK_FALSE(string_contains_special("jaime"));
}
```

### Descriptions

This `TEST_CASE` is missing a description.

```cpp
TEST_CASE("") {
    auto items = std::vector<std::string>{"xdisregard", "climb", "axel", "apex", "xdisregard"};
    // ...
```

Label all `TEST_CASE`s and `SECTION`s so that your tests can be easily followed.

```cpp
TEST_CASE("xector constructed from std::vector range") {
    auto items = std::vector<std::string>{"xdisregard", "climb", "axel", "apex", "xdisregard"};
    // ...
```
