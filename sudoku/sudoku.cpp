#include "generator.hpp"
#include "validSudoku.hpp"
#include "solve.hpp"
#include "sudoku.hpp"
#include <vector>

Sudoku::Sudoku() {} // creates sudoku class

std::vector<std::vector<int>> Sudoku::generate_board() { // uses generator.hpp's generate() function to create class method
    return generate();
}

std::vector<std::vector<int>> Sudoku::make_playable(std::vector<std::vector<int>>& board, int num_blanks) { // uses generator.hpp's makePlayable function to create the class method
    return makePlayable(board, num_blanks);
}

void Sudoku::solve(std::vector<std::vector<int>>& board) { // uses solve.hpp's solve function to recursively backtrack and solve the given board
    ::solve(board);
}

bool Sudoku::is_valid(std::vector<std::vector<int>>& board) { // uses validSudoku.hpp's validSudoku function to check if the board is valid 
    return validSudoku(board);
}
