/**
 * @author Thomas Li
 * @date 2021-06-05
 * @brief Defines unit tests for the Jaro-Winkler algorithm implementation
 */
#include "catch.hpp"

#include "algorithm/jaro_winkler.h"

TEST_CASE("JaroWinklerDistance", "[algorithm]") {
    algorithm::JaroWinkler jw;
    double distance;

    WHEN("The two strings are the same") {
        distance = jw.Distance("SAME", "SAME");

        THEN("Distance should equal one") {
            REQUIRE(distance == 1.0);
        }
    }

    AND_WHEN("The two strings are different") {
        distance = jw.Distance("DIFFERENT", "SAME");
        THEN("Distance should be less than one") {
            REQUIRE(distance < 1.0);
        }
    }

    AND_WHEN("The strings have no common characters") {
        distance= jw.Distance("CAT", "MOUSE");
        THEN("Disttance should be zero") {
            REQUIRE(distance == 0.0);
        }
    }

    AND_WHEN("One string is empty") {
        distance = jw.Distance("SAME", "");
        THEN("Distance should be 0.0") {
            REQUIRE(distance == 0.0);
        }
    }
}
