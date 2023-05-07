#include "solve.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// function checks if you can put a given val at row, col in a given board
bool validMove(const std::vector<std::vector<int>>& board, int val, int row, int col) {
    // checks if val is already in rows
    if (std::find(board[row].begin(), board[row].end(), val) != board[row].end()) {
        return false;
    }

    // checks if val is already in cols
    for (const auto &r : board) {
        if (val == r[col]) {
            return false;
        }
    }

    // checks if val is in the 3x3 row, col is in
    for (int m = (std::floor(row / 3)) * 3; m < (std::floor(row / 3)) * 3 + 3; m++) {
        for (int n = (std::floor(col / 3) * 3); n < (std::floor(col / 3)) * 3 + 3; n++) {
            if (row != m && col != n && board[m][n] == val) {
                return false;
            }
        }
    }

    return true;
}

// finds the first empty cell in a given board (if cell == 0)
std::vector<int> findEmptyCell(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// combines both functions to recursively backtrack and solve the board
bool solve(std::vector<std::vector<int>>& board) {
    std::vector<int> emptyCell = findEmptyCell(board); // finds the first empty cell

    if (emptyCell[0] == -1 && emptyCell[1] == -1) { // if no cell is found, board is solved
        return true;
    }

    int row = emptyCell[0]; // unpacks emptyCell
    int col = emptyCell[1]; // unpacks emptyCell

    // finds which number that is able to be placed at row, col (empty cell)
    for (int num = 1; num < 10; num++) {
        if (validMove(board, num, row, col)) {
            board[row][col] = num; // if found then place the num at row, col

            if (solve(board)) { // recursively continue
                return true;
            }
        }

        board[row][col] = 0; // if it doesn't work out (false) then turn it back to 0 and backtrack
    }

    return false;
}