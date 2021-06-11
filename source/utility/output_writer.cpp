#include <fstream>
#include <vector>

#include "utility/output_writer.h"

using namespace utility;

void OutputWriter::OutputToFile(const std::vector<std::string>& sorted_list) {
    std::ofstream output_file("output.txt");
    for (auto& filename : sorted_list) {
        output_file << filename << std::endl;
    }
    output_file.close();
}