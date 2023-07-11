# k-means-cpp
[![CircleCI](https://dl.circleci.com/status-badge/img/gh/thomastli/k-means-cpp/tree/main.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/thomastli/k-means-cpp/tree/main)
[![CodeFactor](https://www.codefactor.io/repository/github/thomastli/k-means-cpp/badge?s=89ae28b77642813dc4e550544ce24caac5a70f99)](https://www.codefactor.io/repository/github/thomastli/k-means-cpp)
[![codecov](https://codecov.io/gh/thomastli/k-means-cpp/branch/main/graph/badge.svg?token=GBUR8QTLKA)](https://codecov.io/gh/thomastli/k-means-cpp)

C++17 implementation of various k-means style clustering algorithms.

![KMeansCpp](https://github.com/thomastli/k-means-cpp/blob/main/sample_output.png "KMeansCpp")

## Overview
Provides a modern C++17 implementation of k-means (and variants) clustering, using distance algorithms. Originally designed as part of a take-home assignment to cluster filenames. 

### Basic K-means Algorithm (Lloyd's Algorithm)
Given an initial set of k means, perform the following steps:
1. Assignment:
    - Assign each element in the cluster with the nearest mean (the least distance).
2. Update:
    - Recalculate means for elements assigned to each cluster.
3. Convergence:
   - Repeat steps 1 and 2 until assignments no longer change. Terminate.

## Build Instructions (Local)
### Using build script
```shell
./build.sh Release
```

### Using Dockerfile
```shell
docker build -t kmeanscpp .
```

### Manual
```shell
cmake .
make
```

## Dependencies
### Build
- cmake
- make
- gcc-10
- g++-10
- lcov
- gcovr

### Libraries
- [catch](https://github.com/catchorg/Catch2) (included, header-only)
- [easylogging++](https://github.com/amrayn/easyloggingpp) (included)
- [Jaro-Winkler](https://github.com/TriviaMarketing/Jaro-Winkler) (included)

## Supported Algorithms
### Clustering
- [k-medoids](https://en.wikipedia.org/wiki/K-medoids)

### Distance
- [Jaro-Winkler algorithm](https://en.wikipedia.org/wiki/Jaro%E2%80%93Winkler_distance)

## Style Guide
Based off of the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Future work
- Define a generic element for various common data types.
- Implement greedy algorithm for selection of k centroids.
- Add implementations for other clustering algorithms (kmeans++, k-median, etc.)
- Add implementations for other distance algorithms (Levenshtein, Damerau-Levenshtein, etc.)
