#include "./ferrari.h"

#include <catch2/catch.hpp>

/*
Const correct ness


*/

// is function can be invoked by const ferrari type or not
TEST_CASE("ferrari is const-correct") {
    CHECK(std::is_invocable_v<decltype(&ferrari::get_details), const ferrari>);
    CHECK(std::is_invocable_v<decltype(&ferrari::vroom), const ferrari>);
    CHECK_FALSE(std::is_invocable_v<decltype(&ferrari::drive), const ferrari>);
}