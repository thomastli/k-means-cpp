#include <algorithm>
#include <string>

#include "algorithm/jaro_winkler.h"
#include "kmeans/cluster.h"

using namespace kmeans;

void Cluster::Add(const std::string &element) {
    elements_.push_back(element);
    element_index_map_.insert(
            std::pair<std::string, unsigned int>(element, element_index_map_.size())
            );
}

std::string Cluster::At(const unsigned int& index) {
    return elements_[index];
}

int Cluster::Size() {
    return elements_.size();
}

bool Cluster::Empty() {
    return elements_.empty();
}

void Cluster::CreateMatrix() {
    matrix_.Init(elements_.size());
    algorithm::JaroWinkler distance_impl = algorithm::JaroWinkler();

    unsigned int i = 0;
    unsigned int j = 0;

    while(i < elements_.size()) {
        Point same{i, i};
        matrix_.Set(same, 0.0);

        unsigned int end = elements_.size();

        if (j == end) {
            i++;
            j = i;
            break;
        }

        Point point{i, j};
        double distance = 1 - distance_impl.Distance(elements_[i], elements_[j]);
        matrix_.Set(point, distance);

        Point converse_point{j, i};
        matrix_.Set(converse_point, distance);

        j++;
    }
}

double Cluster::GetCost(const std::string &element) {
    if(element_index_map_.empty()) {
        return 0.0;
    }

    unsigned int row = element_index_map_.at(element);
    return matrix_.Cost(row);
}