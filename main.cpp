#include <chrono>
#include <filesystem>
#include <memory>

#include "kmeans/k_medoids.h"
#include "easylogging++.h"
#include "utility/text_parser.h"
#include "utility/output_writer.h"

INITIALIZE_EASYLOGGINGPP

static std::vector<std::string> retrieve_name_list(const std::string& filename) {
    auto parser_impl = std::make_shared<utility::TextParser>();
    std::vector<std::string> name_list = parser_impl->RetrieveList(filename);
    unsigned int records = name_list.size();
    LOG(INFO) << "Retrieved " << records << " record(s) from file";
    return name_list;
}

static void generate_k_means_output(std::vector<std::string>& name_list, unsigned int k_value) {
    LOG(INFO) << "Initializing " << k_value << " cluster(s) from the dataset";

    auto kmeans_interface = std::make_shared<kmeans::KMedoids>(kmeans::KMedoids(name_list, k_value));
    kmeans_interface->Init();
    LOG(INFO) << "Updating " << k_value << " cluster(s)";

    while(!kmeans_interface->HasConverged()) {
        LOG(INFO) << "Iteration level = " << kmeans_interface->IterationLevel();
        kmeans_interface->Update();
    }

    std::vector<std::string> sorted_list = kmeans_interface->Output();
    utility::OutputWriter writer;
    writer.OutputToFile(sorted_list);

    unsigned int iteration = kmeans_interface->IterationLevel() - 1;
    LOG(INFO) << "Created output file in " << iteration << " iteration(s)";
}

int main(int argc, char** argv) {
    if (argc < 3) {
        LOG(ERROR) << "Usage: k-means-cpp [filename] [k-value]";
        exit(1);
    }

    std::string filename = std::string(argv[1]);
    if (!std::filesystem::exists(filename)) {
        LOG(ERROR) << "Filename " << filename << " does not exist";
        exit(2);
    }

    int k_value = std::stoi(argv[2]);
    if(k_value < 2) {
        LOG(ERROR) << "K value must be 2 or more!";
        exit(3);
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> name_list = retrieve_name_list(filename);

    int input_size = static_cast<int>(name_list.size());
    if(input_size < k_value) {
        LOG(ERROR) << "The k value cannot be more than the total number of data entries";
        exit(4);
    }

    generate_k_means_output(name_list, k_value);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    LOG(INFO) << "Elapsed: " << duration << " second(s)";

    return 0;
}
