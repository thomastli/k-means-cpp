#include <catch.hpp>

#include "kmeans/cluster.h"

const double MATRIX_COST = 0.38888888888888895;

TEST_CASE("Cluster::Add", "[kmeans]") {
    std::string element = "filename.txt";
    kmeans::Cluster cluster;
    cluster.Add(element);

    REQUIRE_FALSE(cluster.Empty());
    REQUIRE(cluster.Size() == 1);
}

TEST_CASE("Cluster::At", "[kmeans]") {
    std::string element = "filename.txt";
    kmeans::Cluster cluster;
    cluster.Add(element);

    std::string retrieved_element = cluster.At(0);
    REQUIRE_FALSE(retrieved_element.empty());
}

TEST_CASE("Cluster::CreateMatrix", "[kmeans]") {
    kmeans::Cluster cluster;
    cluster.Add("filename.txt");
    cluster.Add("profile.ovpn");

    REQUIRE_NOTHROW(cluster.CreateMatrix());
}

TEST_CASE("Cluster::Cost", "[kmeans]") {
    kmeans::Cluster cluster;
    cluster.Add("filename.txt");
    cluster.Add("profile.ovpn");

    cluster.CreateMatrix();

    double cost = cluster.GetCost("filename.txt");
    REQUIRE(cost == MATRIX_COST);
    cost = cluster.GetCost("profile.ovpn");
    REQUIRE(cost == MATRIX_COST);
}
