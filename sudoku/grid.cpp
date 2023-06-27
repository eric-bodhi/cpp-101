#include "grid.hpp"
#include <iostream>

int grid::get(int row, int col) const
{
    return data.at(row).at(col);
}

void grid::place(int row, int col, int val)
{
    data.at(row).at(col) = val;
}

void grid::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << this->get(i, j) << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}