#include <numeric>

#include "kmeans/matrix.h"

using namespace kmeans;

void Matrix::Init(const unsigned int &size) {
    size_ = size;
    for(unsigned int i = 0; i < size_ * size_; i++) {
        matrix_.push_back(0.0);
    }
}

double Matrix::Get(Point &point) {
    unsigned int index = point.x * size_ + point.y;
    return matrix_[index];
}

void Matrix::Set(Point &point, const double &distance) {
    unsigned int index = point.x * size_ + point.y;
    matrix_[index] = distance;
}

double Matrix::Cost(unsigned int &row) {
    double cost = 0.0;

    unsigned int i = 0;
    while(i < size_) {
        int index = row * size_ + i;
        cost += matrix_[index];
        i++;
    }

    return cost;
}

std::size_t Matrix::Size() {
    return size_;
}