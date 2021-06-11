/**
 * @author Thomas Li
 * @date 2021-06-06
 * @brief Defines unit tests for an output writer
 */
#include <filesystem>

#include <catch.hpp>

#include "utility/output_writer.h"

TEST_CASE("OutputWriter", "[utility]") {
    std::vector<std::string> sorted_list = {
            "6511380590396154410_glight_EXP_INSTALLED_PATCHES_20030101050000_COMPLETE.gz",
            "6511380590396154410_glight_EXP_INSTALLED_PATCHES_20030101050000.gz",
            "8829209112460573252_tsnider-vm04_EXP_INSTALLED_PATCHES_20030101050000_COMPLETE.gz",
            "8829209112460573252_tsnider-vm04_EXP_INSTALLED_PATCHES_20030101050000.gz",
            "9086595421814992952_vx54_EXP_INSTALLED_PATCHES_20030101050000_COMPLETE.gz",
            "9086595421814992952_vx54_EXP_INSTALLED_PATCHES_20030101050000.gz",
            "DMv2_orna-vm01_EXP_ACCESS_LOG_20170201000000.gz",
            "DMv2_orna-vm01_EXP_ACCESS_LOG_20170201010000.gz",
            "DMv2_orna-vm01_EXP_ACCESS_LOG_20170201020000.gz",
            "DMv2_orna-vm01_EXP_ACCESS_LOG_20170201030000.gz"
    };

    utility::OutputWriter writer;
    writer.OutputToFile(sorted_list);

    REQUIRE(std::filesystem::exists("output.txt"));
}
