/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Implementation of Jaro-Winkler algorithm for edit distance between strings
 * Modified from original source: https://github.com/TriviaMarketing/Jaro-Winkler
 */
#ifndef JAROWINKLER_HPP
#define JAROWINKLER_HPP

#include <string>

#include "distance_interface.h"

namespace algorithm {
    class JaroWinkler : public DistanceInterface {
    public:
        /**
       * Determine the distance between two strings
       * @param a     The first string
       * @param b     The second string
       * @return      The distance, as a double value
       */
        double Distance(const std::string &a, const std::string &b) override;
    private:
        double jaro_distance(const std::string &a, const std::string &b);
    };
}

#endif // JAROWINKLER_HPP

