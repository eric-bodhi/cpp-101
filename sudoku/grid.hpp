#pragma once

#include <vector>

struct grid
{
    std::vector<std::vector<int>> data;

    grid(const std::vector<std::vector<int>> &initialData =
             std::vector<std::vector<int>>(9, std::vector<int>(9)))
        : data(initialData)
    {
    }

    int get(int row, int col) const;
    void place(int row, int col, int val);
    void printBoard();
};

#pragma once