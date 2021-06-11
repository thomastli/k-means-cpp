/**
 * @author Thomas Li
 * @date 2021-06-10
 * @brief Defines a Matrix class to encapsulate storage of distance matrix values
 */
#ifndef K_MEANS_CPP_MATRIX_H
#define K_MEANS_CPP_MATRIX_H

#include <limits>
#include <vector>

namespace kmeans {
    struct Point {
        unsigned int x;
        unsigned int y;
    };

    class Matrix {
    public:
        /**
         * Initialize the matrix
         * @param size      The size, an unsigned int
         */
        void Init(const unsigned int &size);

        /**
         * Get the distance at a particular point (x,y)
         * @param point     The point object
         * @return          The distance, as a double value
         */
        double Get(Point& point);

        /**
         * Set the distance at a particular point (x,y)
         * @param point     The point object
         * @param distance  The distance, as a double value
         */
        void Set(Point& point, const double& distance);

        /**
         * Determine the total cost a row in the matrix
         * @param row   The row id
         * @return      The total cost, as a doublue value
         */
        double Cost(unsigned int &row);

        /**
         * The size of the matrix (the n value of an n*n matrix
         * @return  The size
         */
        std::size_t Size();
    private:
        unsigned int size_;
        std::vector<double> matrix_;
    };
}
#endif //K_MEANS_CPP_MATRIX_H