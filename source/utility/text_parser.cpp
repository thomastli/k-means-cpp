#include <iostream>
#include <fstream>

#include "algorithm/jaro_winkler.h"
#include "utility/text_parser.h"

using namespace utility;

std::vector<std::string> TextParser::RetrieveList(const std::string &filename) {
    std::vector<std::string> name_list;
    std::string line;

    std::ifstream input_file(filename);
    while(std::getline(input_file, line)) {
        name_list.push_back(line);
    }
    input_file.close();

    return name_list;
}