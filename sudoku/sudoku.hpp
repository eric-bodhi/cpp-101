#pragma once

#include "grid.hpp"
#include <optional>
#include <vector>

std::vector<int> shuffle(const std::vector<int> &v);
int pattern(int r, int c, int base);
std::vector<int> generateSequence(std::vector<int> const &base);

class Sudoku
{
public:
    Sudoku(const grid &initialBoard = grid());
    void generate_board();
    void make_playable(int num_blanks);
    bool solve();
    bool is_valid() const;
    grid getBoard() const;

private:
    bool validRows() const;
    bool validCols() const;
    bool validSquares() const;
    bool hasDuplicates(const std::vector<int> &unit) const;

    bool validMove(int val, int row, int col) const;
    std::optional<std::pair<int, int>> findEmptyCell() const;

    grid board;
};

#pragma once