/**
 * @author Thomas Li
 * @date 2021-06-05
 * @brief Defines unit tests for the k-medoids variant of k-means algorithm
 */
#include <catch.hpp>

#include "kmeans/k_medoids.h"

TEST_CASE("KMedoidsInit", "[kmeans]") {
    std::vector<std::string> name_list = { "alpha.a", "beta.bat", "gamma.tar.gz", "omega.ovpn" };
    unsigned int k_value = 2;
    kmeans::KMedoids k_medoids = kmeans::KMedoids(name_list, k_value);
    REQUIRE_NOTHROW(k_medoids.Init());
}

TEST_CASE("KMedoidsUpdate", "[kmeans]") {
    std::vector<std::string> name_list = { "alpha.a", "beta.bat", "gamma.tar.gz", "omega.ovpn" };
    unsigned int k_value = 2;
    kmeans::KMedoids k_medoids = kmeans::KMedoids(name_list, k_value);
    k_medoids.Init();
    while (!k_medoids.HasConverged()) {
        k_medoids.Update();
    }
}

TEST_CASE("KMedoidsOutput", "[kmeans]") {
    WHEN("The cluster list is empty") {
        kmeans::KMedoids k_medoids = kmeans::KMedoids(std::vector<std::string>(), 2);
        THEN("Output should return empty list") {
            std::vector<std::string> sorted_list = k_medoids.Output();
            REQUIRE(sorted_list.empty());
        }
    }

    AND_WHEN("The cluster list has contents") {
        std::vector<std::string> name_list = { "alpha.a", "beta.bat", "gamma.tar.gz", "omega.ovpn" };
        unsigned int k_value = 2;

        kmeans::KMedoids k_medoids = kmeans::KMedoids(name_list, k_value);
        k_medoids.Init();
        while (!k_medoids.HasConverged()) {
            k_medoids.Update();
        }
        std::vector<std::string> output_list = k_medoids.Output();

        THEN("The sorted list should not be empty") {
            REQUIRE_FALSE(output_list.empty());
        }
    }
}

TEST_CASE("KMedoidsIterationLevel", "[kmeans]") {
    std::vector<std::string> name_list = { "alpha.a", "beta.bat", "gamma.tar.gz", "omega.ovpn" };
    unsigned int k_value = 2;

    kmeans::KMedoids k_medoids = kmeans::KMedoids(name_list, k_value);
    k_medoids.Init();
    while (!k_medoids.HasConverged()) {
        k_medoids.Update();
    }
    std::vector<std::string> output_list = k_medoids.Output();

    unsigned int iteration_level = k_medoids.IterationLevel();
    REQUIRE(iteration_level > 0);
}
