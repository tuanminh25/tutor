/*
assert: terminate program on the spot - normally in the code itself

normally in the test suit:

require: stop that section 
check: continue even when false

*/

#include "setdiff.h"

#include <catch2/catch.hpp>

TEST_CASE("Basic arithmetic") {
    int a = 10;
    int b = 6;

    SECTION("a - b should be 4") {
        REQUIRE( 1 == 2); // this section would stop here without advancing downward 
        REQUIRE(a - b == 4); 
        CHECK( 1 == 3 ); // this section would run and still advancing downward 

    }

    SECTION("a + b should be 16") {
        CHECK( 1 == 3); // this section would run and still advancing downward 
        REQUIRE(a + b == 16); // run normally
        CHECK( 1 == 3); // this section would run and still advancing downward 
    
    }

    REQUIRE( 1 == 5 ); // test case would terminate here -> next section would not run
        
    SECTION("a + b should be 16") {
        
        
        SECTION("a + b should be 16") {
            REQUIRE(a + b == 16); 
        }

        REQUIRE(a + b == 16); 
    }
}