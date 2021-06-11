#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <execution>
#include <iostream>
#include <numeric>
#include <mutex>
#include <random>

#include "algorithm/jaro_winkler.h"
#include "kmeans/k_medoids.h"

using namespace kmeans;

//region Public Functions
void KMedoids::Init() {
    std::random_device rand;
    unsigned int seed = time(nullptr);
    auto gen = std::mt19937(rand_r(&seed));

    int end_range = static_cast<int>(name_list_.size() - 1);
    auto range = std::uniform_int_distribution<>(0, end_range);

    clusters_ = set_default_cluster_list_values();

    for (unsigned int i = 0; i < k_value_; i++) {
        std::string centroid = name_list_[range(gen)];
        centroids_.push_back(centroid);
    }

    initialize_cluster();
}

void KMedoids::Update() {
    update_all_centroids();
    centroids_ = new_centroids_;
    update_cluster_list();
    converged_ = update_total_cost();
    iterations_ = iterations_ + 1;
}

std::vector<std::string> KMedoids::Output() {
    std::mutex mutex;
    auto output = [&](Cluster& cluster) {
        std::scoped_lock<std::mutex> lock(mutex);
        output_list(cluster);
    };

    std::for_each(std::execution::par, clusters_.begin(), clusters_.end(), output);
    return sorted_list_;
}

bool KMedoids::HasConverged() {
    return converged_;
}

unsigned int KMedoids::IterationLevel() {
    return iterations_;
}
//endregion !Public Functions

//region Private Functions
ClusterList KMedoids::set_default_cluster_list_values() {
    ClusterList cluster_list;
    for (unsigned int i = 0; i < k_value_; i++) {
        cluster_list.push_back(Cluster());
    }
    return cluster_list;
}

void KMedoids::initialize_cluster() {
    std::mutex mutex;
    auto initialize = [&](std::string& name) {
        std::scoped_lock<std::mutex> locK(mutex);
        unsigned int id = find_closest_cluster(name);
        clusters_[id].Add(name);
    };

    std::for_each(std::execution::par, name_list_.begin(), name_list_.end(), initialize);
    new_clusters_ = clusters_;
}

void KMedoids::update_cluster_list() {
    std::mutex mutex;
    new_clusters_ = set_default_cluster_list_values();
    auto find_cluster_for_node = [&](std::string& name) {
        std::scoped_lock<std::mutex> lock(mutex);
        unsigned int i = find_closest_cluster(name);
        new_clusters_[i].Add(name);
    };

    std::for_each(std::execution::par, name_list_.begin(), name_list_.end(), find_cluster_for_node);
}

unsigned int KMedoids::find_closest_cluster(std::string &node) {
    int id = 0;
    double distance = std::numeric_limits<double>::max();
    distance_impl_ = std::make_shared<algorithm::JaroWinkler>();

    // Find centroid with closest distance
    int i = 0;
    for(auto& centroid : centroids_) {
        double new_distance = 1 - distance_impl_->Distance(node, centroid);

        if(new_distance < distance) {
            distance = new_distance;
            id = i;
        }
        i++;
    }

    return id;
}

void KMedoids::update_all_centroids() {
    unsigned int i = 0;

    std::mutex mutex;
    auto find_centroid_for_cluster = [&](Cluster& cluster) {
        std::scoped_lock<std::mutex> lock(mutex);
        update_centroid(cluster, i);
        i++;
    };

    std::for_each(std::execution::par, clusters_.begin(), clusters_.end(), find_centroid_for_cluster);
}

void KMedoids::update_centroid(Cluster &cluster, unsigned int &id) {
    std::string centroid = centroids_[id];
    double cost = std::numeric_limits<double>::max();

    for (int i = 0; i < cluster.Size(); i++) {
        std::string new_centroid = cluster.At(i);
        double new_cost = cluster.GetCost(new_centroid);

        if (new_cost < cost) {
            //Update centroid and cost
            centroid = new_centroid;
            cost = new_cost;
        }
    };

    new_centroids_.push_back(centroid);
}

bool KMedoids::update_total_cost() {
    double new_cost = 0.0;
    int i = 0;
    for (auto cluster : new_clusters_) {
        cluster.CreateMatrix();
        std::string centroid = centroids_[i];
        new_cost += cluster.GetCost(centroid);
        i++;
    }

    double old_cost = 0.0;
    int j = 0;
    for (auto& cluster : clusters_) {
        cluster.CreateMatrix();
        std::string centroid = centroids_[j];
        old_cost += cluster.GetCost(centroid);
        j++;
    }

    if(new_cost < old_cost) {
        clusters_ = new_clusters_;
        centroids_ = new_centroids_;
        new_clusters_ = set_default_cluster_list_values();
        new_centroids_.clear();
        return false;
    }
    return true;
}

void KMedoids::output_list(Cluster &cluster) {
    if (cluster.Empty()) {
        return;
    }

    for(int i = 0; i < cluster.Size(); i++) {
        std::string element = cluster.At(i);
        sorted_list_.push_back(element);
    };
}
//endregion Private Functions