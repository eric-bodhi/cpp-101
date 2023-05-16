#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>
#include "grid.hpp"

std::vector<int> shuffle(const std::vector<int>& v); 
int pattern(int r, int c, int base);


class Sudoku {
public:
    Sudoku();
    void generate_board();
    void make_playable(int num_blanks);
    bool solve();
    bool is_valid() const;
    std::vector<std::vector<int>> getBoard() const;

    bool validRows() const;
    bool validCols() const;
    bool validSquares() const;
    bool validUnit(const std::vector<int>& unit) const;

    bool validMove(int val, int row, int col) const;
    std::pair<int, int> findEmptyCell() const;

private:
    grid board;
};

#endif // SUDOKU_HPP
