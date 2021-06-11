/**
 * @uathor Thomas Li
 * @date 2021-06-05
 * @brief Defines unit tests for the TextParser class
 */
#include <catch.hpp>

#include "utility/text_parser.h"

const std::string TEST_FILE = "test_file.txt";

TEST_CASE("TextParserRetrieveList", "[utility]") {
    utility::TextParser parser;
    std::vector<std::string> list = parser.RetrieveList(TEST_FILE);
    REQUIRE_FALSE(list.empty());
}