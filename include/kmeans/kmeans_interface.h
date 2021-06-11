/**
 * @author Thomas Li
 * @date 2021-06-05
 * @brief Defines a base interface for a kmeans-style clustering algorithm
 */

#ifndef K_MEANS_CPP_KMEANS_INTERFACE_H
#define K_MEANS_CPP_KMEANS_INTERFACE_H

namespace kmeans {
    class KMeansInterface {
    public:
        /**
         * Initialize the k-means algorithm
         */
        virtual void Init() = 0;

        /**
         * Update the clusters and centroids of the algorithm
         */
        virtual void Update() = 0;

        /**
         * Output the clustered data as a list
         * @return          The list, a std::vector<std::string>
         */
        virtual std::vector<std::string> Output() = 0;

        /**
         * Check if the algorithm has converged
         * @return true     If converged
         * @return false    Otherwise
         */
        virtual bool HasConverged() = 0;

        /**
         * Retrieve the iteration level
         * @return          The iteration level, an unsigned int
         */
        virtual unsigned int IterationLevel() = 0;
    };
}
#endif //K_MEANS_CPP_KMEANS_INTERFACE_H
