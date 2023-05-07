#include "generator.hpp"
#include "validSudoku.hpp"
#include "solve.hpp"
#include "sudoku.hpp"
#include <vector>

Sudoku::Sudoku() {}

std::vector<std::vector<int>> Sudoku::generate_board() {
    return generate();
}

std::vector<std::vector<int>> Sudoku::make_playable(std::vector<std::vector<int>>& board, int num_blanks) {
    return makePlayable(board, num_blanks);
}

void Sudoku::solve(std::vector<std::vector<int>>& board) {
    ::solve(board);
}

bool Sudoku::is_valid(std::vector<std::vector<int>>& board) {
    return validSudoku(board);
}
