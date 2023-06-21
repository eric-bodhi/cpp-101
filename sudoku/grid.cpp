#include "grid.hpp"
#include <stdexcept>

int grid::get(int row, int col) const
{
    return data.at(row).at(col);
}

void grid::place(int row, int col, int val)
{
    data.at(row).at(col) = val;
}
