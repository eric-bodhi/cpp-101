#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

class Sudoku {
public:
    Sudoku();
    std::vector<std::vector<int>> generate_board();
    std::vector<std::vector<int>> make_playable(std::vector<std::vector<int>>& board, int num_blanks);
    void solve(std::vector<std::vector<int>>& board);
    bool is_valid(std::vector<std::vector<int>>& board);
};

#endif
