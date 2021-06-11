/**
 * @author Thomas Li
 * @date 2021-06-04
 * @brief Defines a filename list writer
 */
#ifndef K_MEANS_CPP_OUTPUT_WRITER_H
#define K_MEANS_CPP_OUTPUT_WRITER_H

namespace utility {
    class OutputWriter {
    public:
        /**U
         * Output a sorted list to a file
         * @param sorted_list   The sorted list, a std::vector<std::string>
         */
        void OutputToFile(const std::vector<std::string>& sorted_list);
    };
}

#endif //K_MEANS_CPP_OUTPUT_WRITER_H
