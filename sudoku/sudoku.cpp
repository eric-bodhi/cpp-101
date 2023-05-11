#include "sudoku.hpp"
#include "generator.hpp"
#include "solve.hpp"
#include "validSudoku.hpp"

Sudoku::Sudoku() : board(9, std::vector<int>(9)) {}

void Sudoku::generate_board() {
    this->board = generate();
}

void Sudoku::make_playable(int num_blanks) {
    this->board = makePlayable(this->board, num_blanks);
}

void Sudoku::solve() {
    ::solve(this->board);
}

bool Sudoku::is_valid() const {
    return validSudoku(this->board);
}

std::vector<std::vector<int>> Sudoku::getBoard() const {
    return this->board;
}