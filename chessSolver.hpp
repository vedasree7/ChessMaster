#ifndef CHESS_SOLVER_HPP
#define CHESS_SOLVER_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Sorting.hpp"

using namespace std;

/**
 * Handles:
 * - Creating and managing a 2D matrix
 * - Sorting each row ascending/descending
 * - Counting inversions in flattened 1D version of the matrix
 * - Displaying the matrix
 */
class ChessSolver {
private:
    vector<vector<long long>> matrix;
    int size;

public:
    ChessSolver() {}

    // Initializes the matrix by taking input values
    ChessSolver(int n) : size(n) {
        matrix.resize(size, vector<long long>(size));
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> matrix[i][j];
    }

    /**
     * Sorts each row of the matrix:
     * - If descending is false: sort ascending
     * - If descending is true: sort ascending then reverse
     */
    void sortRows(bool descending) {
        for (int i = 0; i < size; i++) {
            Sorting sorter;
            sorter(matrix[i], 0, matrix[i].size() - 1);
            if (descending)
                reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    /**
     * Flattens the 2D matrix into a 1D vector row-wise
     * and returns the inversion count using merge sort.
     */
    long long countInversions() {
        vector<long long> flattened;
        for (const auto &row : matrix)
            flattened.insert(flattened.end(), row.begin(), row.end());

        return mergeAndCount(flattened, 0, flattened.size() - 1);
    }

    /**
     * Displays the matrix in row-wise order.
     */
    void display() {
        for (const auto &row : matrix) {
            for (long long val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

#endif
