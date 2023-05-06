#ifndef SUDOKU_BOARD_GENERATOR_HPP
#define SUDOKU_BOARD_GENERATOR_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

std::vector<int> shuffle(const std::vector<int>& v) {
    std::vector<int> result = v;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

int pattern(int r, int c, int base) {
    int side = base * base;
    return (base * (r % base) + r / base + c) % side;
}

std::vector<std::vector<int>> generate_board() {
    int base = 3;
    int side = base * base;

    std::vector<int> rBase(base);
    std::iota(rBase.begin(), rBase.end(), 0);
    std::vector<int> rows;
    std::vector<int> cols;
    std::vector<int> nums(side);
    std::iota(nums.begin(), nums.end(), 1);

    for (auto g : shuffle(rBase)) {
        for (auto r : shuffle(rBase)) {
            rows.push_back(g * base + r);
        }
    }

    for (auto g : shuffle(rBase)) {
        for (auto c : shuffle(rBase)) {
            cols.push_back(g * base + c);
        }
    }

    nums = shuffle(nums);

    std::vector<std::vector<int>> board(side, std::vector<int>(side));

    for (int r = 0; r < rows.size(); r++) {
        for (int c = 0; c < cols.size(); c++) {
            board[r][c] = nums[pattern(rows[r], cols[c], base)];
        }
    }

    return board;
}

std::vector<std::vector<int>> makePlayable(std::vector<std::vector<int>> board, const int val) {
    std::vector<int> indices(81);
    std::iota(indices.begin(), indices.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    for (int i = 0; i < val; ++i) {
        int index = indices[i];
        board[index / 9][index % 9] = 0;
    }

    return board;
}

#endif