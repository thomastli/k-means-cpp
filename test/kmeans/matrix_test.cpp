/**
 * @author Thomas Li
 * @date 2021-06-10
 * @brief Defines unit tests for the Matrix class
 */
#include <catch.hpp>

#include "kmeans/matrix.h"

TEST_CASE("Matrix::Init", "[kmeans]") {
    kmeans::Matrix matrix;
    matrix.Init(2);

    REQUIRE(matrix.Size() == 2);
}

TEST_CASE("Matrix::Set", "[kmeans]") {
    kmeans::Matrix matrix;
    matrix.Init(2);

    kmeans::Point point{ 0, 0};
    REQUIRE_NOTHROW(matrix.Set(point, 0.0));
}

TEST_CASE("Matrix::Get", "[kmeans]") {
    kmeans::Matrix matrix;
    matrix.Init(2);

    kmeans::Point point{ 0, 0};
    matrix.Set(point, 1.0);
    REQUIRE(matrix.Get(point) == 1.0);
}

TEST_CASE("Matrix::Cost", "[kmeans]") {
    int size = 2;
    kmeans::Matrix matrix;
    matrix.Init(size);

    kmeans::Point point{ 0, 0};
    matrix.Set(point, 0.0);
    point = kmeans::Point{0, 1};
    matrix.Set(point, 1.0);
    point = kmeans::Point{1, 0};
    matrix.Set(point, 2.0);
    point = kmeans::Point{1, 1};
    matrix.Set(point, 0);

    unsigned int row = 0;
    REQUIRE(matrix.Cost(row) == 1);
    row = 1;
    REQUIRE(matrix.Cost(row) == 2);
}
