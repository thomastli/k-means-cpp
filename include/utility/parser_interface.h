/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Defines base parser interface
 */
#ifndef JARO_WINKLER_CLUSTER_PARSER_INTERFACE_H
#define JARO_WINKLER_CLUSTER_PARSER_INTERFACE_H

#include <string>
#include <vector>

namespace utility {
    class ParserInterface {
        /**
         * Retrieve an input list from the parser
         * @param filename  The filename, as a std::string
         * @return          The list, as a std::vector<std::string>
         */
        virtual std::vector<std::string> RetrieveList(const std::string& filename) = 0;
    };

}
#endif //JARO_WINKLER_CLUSTER_PARSER_INTERFACE_H
