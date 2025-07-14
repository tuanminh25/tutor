#include <catch2/catch.hpp>

#include <stdexcept>

#include "./x_vector.h"

TEST_CASE("check that .at throws exception for bad index access") {
    auto states = xector{"california", "texas", "florida", "new mexico"};

    SECTION("check that poor access throws error") {
        CHECK_THROWS(states.at(2)); // check throwing or not
    }

    SECTION("verify that a std::out_of_range is thrown") {
        CHECK_THROWS_AS(states.at(2), std::out_of_range); // check specific type of error being thrown
    }

    SECTION("confirm error message") {
        CHECK_THROWS_WITH(states.at(2), "index 2 is out of range for an xector of size 2"); // check throw message
    }
    
    CHECK_THROWS_MATCHES(states.at(2), std::out_of_range, 
    Catch::Matchers::Message("index 2 is out of range for an xector of size 2")); // check everything at once
}
