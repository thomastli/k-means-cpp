/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Implementation of ParserInterface for filename lists
 */
#ifndef JARO_WINKLER_CLUSTER_FILENAME_PARSER_H
#define JARO_WINKLER_CLUSTER_FILENAME_PARSER_H

#include <string>
#include <vector>

#include "parser_interface.h"

namespace utility {
    class TextParser : ParserInterface {
    public:
        /**
         * Retrieve an input list from a specific filename using the parser
         * @param filename  The filename, as a std::string
         * @return          The input list, as a std::vector<std::string>
         */
        std::vector<std::string> RetrieveList(const std::string& filename) override;
    };
}
#endif //JARO_WINKLER_CLUSTER_FILENAME_PARSER_H
