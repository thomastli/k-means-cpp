/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Implementation of k-medoids algorithm for clustering
 */
#ifndef K_MEANS_CPP_KMEANS_H
#define K_MEANS_CPP_KMEANS_H

#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

#include "algorithm/distance_interface.h"
#include "cluster.h"
#include "kmeans_interface.h"

using ClusterList = std::vector<kmeans::Cluster>;

namespace kmeans {
    class KMedoids : public KMeansInterface {
    public:
        /**
         * Construct a KMedoids object
         * @param name_list     The input list of names
         * @param k_value       The k value or number of clusters
         */
        KMedoids(const std::vector<std::string> &name_list, const unsigned int &k_value) :
            name_list_(name_list),
            k_value_(k_value)
            {}

        /**
         * Initialize the KMedoids object
         */
        void Init() override;

        /**
         * Update the clusters, centroids, and any associated data
         */
        void Update() override;

        /**
         * Output the clustered data in a list
         * @return      The list, as a std::vector<std::string>
         */
        std::vector<std::string> Output() override;

        /**
         * Determine whether the algorithm has converged.
         * @return true     If converged
         * @return false    Otherwise
         */
        bool HasConverged() override;

        /**
         * Get the current iteration level of the algorithm
         * @return  The iteration level, as an unsigned int
         */
        unsigned int IterationLevel() override;

    private:
        ClusterList set_default_cluster_list_values();
        void initialize_cluster();
        void update_cluster_list();
        unsigned int find_closest_cluster(std::string &node);
        void update_all_centroids();
        void update_centroid(Cluster &cluster, unsigned int &id);
        bool update_total_cost();
        void output_list(Cluster &cluster);

        std::vector<std::string> name_list_;
        unsigned int k_value_;
        std::shared_ptr<algorithm::DistanceInterface> distance_impl_;
        ClusterList clusters_;
        std::vector<std::string> centroids_;
        ClusterList new_clusters_;
        std::vector<std::string> new_centroids_;
        std::vector<std::string> sorted_list_;
        bool converged_ = false;
        unsigned int iterations_ = 1;
    };
}
#endif //K_MEANS_CPP_KMEANS_H
