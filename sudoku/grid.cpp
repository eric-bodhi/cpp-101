#include "grid.hpp"
#include <stdexcept>

int grid::get(int row, int col) const {
    if (row < 0 || row >= 9 || col < 0 || col >= 9) {
        // Error: out of bounds
        throw std::out_of_range("Row or column index out of bounds");
    }

    return data[row][col];
}

void grid::place(int row, int col, int val) {
    if (row < 0 || row >= 9 || col < 0 || col >= 9) {
        // Error: out of bounds
        throw std::out_of_range("Row or column index out of bounds");
    }

    data[row][col] = val;
}


