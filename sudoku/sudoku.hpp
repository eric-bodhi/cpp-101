#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>

class Sudoku {
public:
    Sudoku();
    void generate_board();
    void make_playable(int num_blanks);
    void solve();
    bool is_valid();
    std::vector<std::vector<int>> getBoard();

private:
    std::vector<std::vector<int>> board;
};

#endif // SUDOKU_HPP
