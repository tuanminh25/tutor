#include "scale.h"

/*
static_cast: Fast but unsafe (no type check).

dynamic_cast: Safe but slower (uses RTTI for type check).

what is static and dynamic cast?

static_cast -> when sure cast is safe at compile time (speed over robust)

    + Compile-time cast.

    + Used when the conversion is known to be safe (e.g., base to derived or vice versa, primitive
types).

    + No runtime check, so invalid casts can lead to undefined behavior.

    + Faster, but less safe.

dynamic_cast -> not sure type need safe check (robust over speed)

    + Runtime cast, used with polymorphic types (must have at least one virtual function).

    + Safe for casting down the inheritance hierarchy.

    + Performs a runtime type check.

        Returns a valid pointer or nullptr for invalid pointer casts.

        Throws std::bad_cast for invalid references.


*/

// use static_cast to change from vec int to vec double,
// each of the int in vector, mul it with factor

// default value of 0.5 for the scaling factor
// auto scale(std::vector<int> &ivec, double factor = 0.5) -> std::vector<double>;

auto scale(std::vector<int>& ivec, double factor) -> std::vector<double> {
	std::vector<double> v;

	for (auto& i : ivec) {
		auto new_d = static_cast<double>(i) * factor;
		v.emplace_back();
	}

	return {};
}
