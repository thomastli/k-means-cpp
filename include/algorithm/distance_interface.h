/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Defines a base implementation of a edit distance algorithm
 */
#ifndef K_MEANS_CPP_DISTANCE_INTERFACE_H
#define K_MEANS_CPP_DISTANCE_INTERFACE_H

namespace algorithm {
    class DistanceInterface {
    public:
        /**
         * Determine the distance between two strings
         * @param a     The first string
         * @param b     The second string
         * @return      The distance, as a double value
         */
        virtual double Distance(const std::string& a, const std::string& b) = 0;
    };
}
#endif //K_MEANS_CPP_DISTANCE_INTERFACE_H
