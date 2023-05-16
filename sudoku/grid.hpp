#pragma once

#include <vector>

struct grid {
    std::vector<std::vector<int>> data;

    grid() : data(9, std::vector<int>(9)) {}

    int get(int row, int col) const;
    void place(int row, int col, int val);
};

#pragma once