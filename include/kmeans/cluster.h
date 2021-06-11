/**
 * @author Thomas Li
 * @date 2021-06-10
 * @brief Defines a cluster class to encapsulate the storage of elements
 */
#ifndef K_MEANS_CPP_CLUSTER_H
#define K_MEANS_CPP_CLUSTER_H

#include <unordered_map>

#include "matrix.h"

namespace kmeans {
    class Cluster{
    public:
        /**
         * Add an element to the cluster
         * @param element   The element, a std::string
         */
        void Add(const std::string& element);

        /**
         * Retrieve element at an index in the cluster
         * @param index     The index, an unsigned integer
         * @return          The element, a std::string
         */
        std::string At(const unsigned int& index);

        /**
         * Return the size of the cluster
         * @return          The size
         */
        int Size();

        /**
         * Check whether the cluster is empty
         * @return true     If there are no elements in the cluster
         * @return false    Otherwise
         */
        bool Empty();

        /**
         * Create a distance matrix for the cluster
         */
        void CreateMatrix();

        /**
         * Determine cost of a specific element if it was the centroid of the cluster
         * @param element   The element, as a std::string
         * @return          The cost, as a double
         */
        double GetCost(const std::string& element);
    private:
        std::vector<std::string> elements_{};
        std::unordered_map<std::string, unsigned int> element_index_map_;
        Matrix matrix_{};
    };
}
#endif //K_MEANS_CPP_CLUSTER_H
