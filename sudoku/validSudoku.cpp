#include <vector>
#include <algorithm>
#include "validSudoku.hpp"

// checks if a given unit (square, col, or row) follows rules of sudoku
bool validUnit(const std::vector<int>& unit) { 
    std::vector<int> seen;

    for (const auto &i : unit) {
        if (std::find(seen.begin(), seen.end(), i) == seen.end()) {
            seen.push_back(i);
        }

        else {
            return false;
        }
    }

    return true;
}

// checks if rows are valid (according to sudoku)
bool validRows(const std::vector<std::vector<int>>& board) {
    for (const auto &row : board) {
        if (!validUnit(row)) {
            return false;
        }
    }
    
    return true;
}

// checks if cols are valid (according to sudoku)
bool validCols(const std::vector<std::vector<int>>& board) {
    std::vector<std::vector<int>> columns(9, std::vector<int>(9));

    for (int c = 0; c < 9; c++) {
        for (int r = 0; r < 9; r++) {
            columns[c][r] = board[r][c];
        }
    }

    for (const auto &col : columns) {
        if (!validUnit(col)) {
            return false;
        }
    }

    return true;
}

// checks if squares are valid (according to sudoku)
bool validSquares(const std::vector<std::vector<int>>& board) {
    for (int i = 3; i < 10; i += 3) {
        for (int j = 3; j < 10; j += 3) {
            std::vector<int> square;

            for (int k = 0; k < 3; ++k) {
                square.insert(square.end(), board[i-3+k].begin() + (j-3), board[i-3+k].begin() + j);
            }

            if (!validUnit(square)) {
                return false;
            }
        }
    }

    return true;
}

// combines all 4 functions to find if board is valid or not
bool validSudoku(const std::vector<std::vector<int>>& board) {
    return (validRows(board) && validCols(board) && validSquares(board));
}